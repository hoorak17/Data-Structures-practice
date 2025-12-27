#include "subway.h"
#include <fstream>
#include <queue>
#include <algorithm>

Subway::Subway() {}

static std::string makeKey(int line, const std::string& station) {
    return std::to_string(line) + "|" + station;
}//호선과 역이름 하나의 덩어리로

int Subway::findId(int line, const std::string& station) const {
    auto it = idMap.find(makeKey(line, station));
    if (it == idMap.end()) return -1;
    return it->second;
}

int Subway::getId(int line, const std::string& station) {
    std::string key = makeKey(line, station);
    auto it = idMap.find(key);
    if (it != idMap.end()) return it->second;

    int id = (int)nodes.size();
    idMap[key] = id;
    nodes.push_back({line, station});
    adj.push_back(std::vector<Edge>());
    stationGroup[station].push_back(id);//환승
    return id;
}

void Subway::addEdge(int a, int b, int w) {
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
}

bool Subway::loadStations(const std::string& file) {
    std::ifstream fin(file);
    if (!fin.is_open()) return false;

    int m;
    fin >> m;

    for (int i = 0; i < m; i++) {
        int l1, l2;
        std::string s1, s2;
        fin >> l1 >> s1 >> l2 >> s2;

        int a = getId(l1, s1);
        int b = getId(l2, s2);

        int w = (l1 == l2) ? 60 : 30;
        addEdge(a, b, w);
    }

    // 같은 역 이름이면 환승, 30초 추가됨
    for (auto &kv : stationGroup) {
        const std::vector<int>& ids = kv.second;
        for (int i = 0; i < (int)ids.size(); i++) {
            for (int j = i + 1; j < (int)ids.size(); j++) {
                addEdge(ids[i], ids[j], 30);
            }
        }
    }

    return true;
}

void Subway::dijkstra(int start, std::vector<int>& dist, std::vector<int>& prev) {//다익스트라
    int n = (int)nodes.size();
    dist.assign(n, INF);
    prev.assign(n, -1);

    using P = std::pair<int,int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (auto &e : adj[u]) {
            int v = e.to;
            int nd = d + e.w;
            if (nd < dist[v]) {
                dist[v] = nd;
                prev[v] = u;
                pq.push({nd, v});
            }
        }
    }
}

void Subway::recover(int start, int end, const std::vector<int>& prev, std::vector<std::string>& outNames) {
  
    outNames.clear();

    std::vector<int> ids;
    int cur = end;
    while (cur != -1) {
        ids.push_back(cur);
        if (cur == start) break;
        cur = prev[cur];
    }
    std::reverse(ids.begin(), ids.end());
    if (ids.empty() || ids.front() != start) return;

    std::string last = "";
    for (int id : ids) {
        const std::string& nm = nodes[id].station;
        if (outNames.empty() || nm != last) {
            outNames.push_back(nm);
            last = nm;
        }
    }
}

int Subway::shortestPath(int l1, const std::string& s1, int l2, const std::string& s2, std::vector<std::string>& pathStations) {
    pathStations.clear();

    int start = findId(l1, s1);
    int end   = findId(l2, s2);
    if (start == -1 || end == -1) return -1;

    std::vector<int> dist, prev;
    dijkstra(start, dist, prev);

    if (dist[end] >= INF) return -1;

    recover(start, end, prev, pathStations);
    return dist[end];
}


bool Subway::findMidStation(int l1, const std::string& s1, int l2, const std::string& s2, std::string& meet, int& bigT, int& smallT) {
    meet = "";//문b
    bigT = -1;
    smallT = -1;

    int aStart = findId(l1, s1);
    int bStart = findId(l2, s2);
    if (aStart == -1 || bStart == -1) return false;

    std::vector<int> distA, prevA, distB, prevB;
    dijkstra(aStart, distA, prevA);
    dijkstra(bStart, distB, prevB);

    std::map<std::string, int> minA, minB;

    for (int i = 0; i < (int)nodes.size(); i++) {
        if (distA[i] < INF) {
            if (!minA.count(nodes[i].station) || distA[i] < minA[nodes[i].station])
                minA[nodes[i].station] = distA[i];
        }
        if (distB[i] < INF) {
            if (!minB.count(nodes[i].station) || distB[i] < minB[nodes[i].station])
                minB[nodes[i].station] = distB[i];
        }
    }

    int bestDiff = INF, bestMax = INF;
    std::string bestName = "";

    for (auto &kv : minA) {
        const std::string& name = kv.first;
        if (!minB.count(name)) continue;

        int ta = kv.second;
        int tb = minB[name];
        int diff = (ta > tb) ? ta - tb : tb - ta;
        int mx   = (ta > tb) ? ta : tb;

        if (diff < bestDiff ||
            (diff == bestDiff && mx < bestMax) ||
            (diff == bestDiff && mx == bestMax && name < bestName)) {
            bestDiff = diff;
            bestMax = mx;
            bestName = name;
        }
    }

    if (bestName == "") return false;

    meet = bestName;
    int ta = minA[bestName];
    int tb = minB[bestName];
    if (ta >= tb) { bigT = ta; smallT = tb; }
    else { bigT = tb; smallT = ta; }

    return true;
}



std::string Subway::formatTime(int sec) {
    int m = sec / 60;
    int s = sec % 60;

    std::string res = std::to_string(m) + ":";
    if (s < 10) res += "0";
    res += std::to_string(s);

    return res;
}