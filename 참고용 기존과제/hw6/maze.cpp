#include <iostream>
#include <stack>
using namespace std;
const int MAXSIZE = 100; // up to 100 by 100 maze allowed
bool maze[MAXSIZE + 2][MAXSIZE + 2];
bool mark[MAXSIZE + 1][MAXSIZE + 1] = {0};
enum directions { N, NE, E, SE, S, SW, W, NW };
struct offsets {
    int a, b;
} move[8] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1},
 {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
struct Items {
    Items(int xx = 0, int yy = 0, int dd = 0) : x(xx), y(yy), dir(dd) {}
    int x, y, dir;
};
template <class T>
ostream& operator<<(ostream& os, stack<T>& s) {
 // 스택의 내용을 역순으로 출력
 // 구현방법=내용을 하나씩 꺼내 다른 임시 스택에 넣어 저장한 후,
 // 최종적으로 그 임시 스택에서 하나씩 꺼내 출력하면 됨
    stack<T> temp; // 역으로 출력하기 위해 임시 스택 temp 이용
 /*
 TODO: 이 부분 작성
 */
    return os;
}
ostream& operator<<(ostream& os, Items& item) {
 // 5 개의 Items 가 출력될 때마다 줄바꾸기위해
    static int count = 0;
    os << "(" << item.x << "," << item.y << ")";
    count++;
    if ((count % 5) == 0) cout << endl;
    return os;
}
void Path(const int m, const int p) {
 mark[1][1] = 1;
 stack<Items> stack; // C++ STD stack 을 이용하기
 Items temp(1, 1, E);
 stack.push(temp);
 /* 최종적인 경로의 출력은 다음과 같이 한다.
 cout << stack;
 temp.x = i; temp.y = j; cout << " -> " << temp;
 temp.x = m; temp.y = p; cout << " -> " << temp << endl;
 */
}
void ShortestPath(const int m, const int p) {
 /*
 TODO: 더 실습해보고 싶은 학생들 작성
 다음 페이지의 ‘4. 생각해보기’ 참고
 */
 /*
 hw6.cpp 의 main 함수도 Path 와 ShortestPath 둘 다 출력될 수
 있도록 수정 및 출력 결과 구분
 (e.g. Path 의 결과: ~~~ \n ShortestPath 의 결과: ~~~)
 */
}
void getdata(istream& is, int& m,
 int& p) { // 자료화일을 읽어들여 maze 에 저장한다.
 is >> m >> p;
 for (int i = 0; i < m + 2; i++) {
 maze[i][0] = 1;
 maze[i][p + 1] = 1;
 }
 for (int j = 1; j <= p; j++) {
 maze[0][j] = 1;
 maze[m + 1][j] = 1;
 }
 for (int i = 1; i <= m; i++)
 for (int j = 1; j <= p; j++) is >> maze[i][j];
}