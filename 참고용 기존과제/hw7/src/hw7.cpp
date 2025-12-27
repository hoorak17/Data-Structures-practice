#include <iostream>
#include "post.h"
using namespace std;

void Postfix(Expression);

int main() {
    cout<<"C211171"<<endl;//학번출력

    char line[MAXLEN];//MAXLEN 80으로 제시됨.
    while (cin.getline(line, MAXLEN))//한줄씩 읽어온다.
    {

    Expression e(line); // line 버퍼를 이용하여 Expression 을 읽음

    try {
       Postfix(e);
    }

    catch (char const *msg) {
        cerr << "Exception: " << msg << endl;
    }
    
    }
}