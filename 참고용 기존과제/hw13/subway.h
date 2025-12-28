#ifndef SUBWAY_H
#define SUBWAY_H

#include <string>
#include <vector>
#include <map>

struct Node {//노드
    int line;              // 몇호선
    std::string station;   // 역 이름
};

struct Edge {//엣지
    int to;
    int w;                 // seconds
};

class Subway {//지하철클래스

public:
    Subway();

    bool loadStations(const std::string& file);//지도만들기

    int shortestPath(int l1, const std::string& s1, int l2, const std::string& s2, std::vector<std::string>& pathStations);
    //최단경로찾기 문a
    
    bool findMidStation(int l1, const std::string& s1, int l2, const std::string& s2, std::string& meet, int& bigT, int& smallT);
    //중간경로찾기 문b

    static std::string formatTime(int sec);

private:
    //노드를 컴에서는 Id로 다루기
    int getId(int line, const std::string& station); // 없으면 만들고 id 반환

    int findId(int line, const std::string& station) const; // 없으면 -1

    void addEdge(int a, int b, int w);

    void dijkstra(int start, std::vector<int>& dist, std::vector<int>& prev);

    void recover(int start, int end, const std::vector<int>& prev, std::vector<std::string>& outNames);//경로복원

private:
    static constexpr int INF = 1000000000;

    std::vector<Node> nodes;//노드

    std::vector<std::vector<Edge>> adj;

    std::map<std::string, int> idMap;//문자열에서 id로

    std::map<std::string, std::vector<int>> stationGroup;//환승
};

#endif