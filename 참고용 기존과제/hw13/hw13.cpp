#include "subway.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) return 1;

    Subway sw;//지하철만들기
    if (!sw.loadStations(argv[1])) return 1;

    ifstream fin(argv[2]);
    int l1, l2;
    string s1, s2;
    fin >> l1 >> s1 >> l2 >> s2;

    //a번문제
    vector<string> path;
    int total = sw.shortestPath(l1, s1, l2, s2, path);
    for (string &x : path) cout << x << "\n";
    cout << Subway::formatTime(total) << "\n";

    //b번문제
    string meet;
    int bigT, smallT;
    sw.findMidStation(l1, s1, l2, s2, meet, bigT, smallT);
    cout << meet << "\n";
    cout << Subway::formatTime(bigT) << "\n";
    cout << Subway::formatTime(smallT) << "\n";

    return 0;
}