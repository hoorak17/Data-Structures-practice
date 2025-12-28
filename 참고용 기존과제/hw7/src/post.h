#ifndef __POSTFIX_H__
#define __POSTFIX_H__
#include <iostream>

// token types for non one-char tokens
#define ID 257//식별자임을 알림
#define NUM 258//숫자임을 알림
#define EQ 259//equal
#define NE 260//not equal
#define GE 261//>=
#define LE 262//<=
#define AND 263//&&
#define OR 264//||
#define UMINUS 265//음수부호
#define MAXLEN 80

struct Expression {
    Expression(char* s) : str(s), pos(0) {
    for (len = 0; str[len] != '\0'; len++)
        ;
    }
    char* str;
    int pos;
    int len;
};//어디까지 읽었나 표시

struct Token {
    bool operator==(char);
    bool operator!=(char);
    //연산자오버로딩
    
    Token();
    Token(char); // 1-char token: type equals the token itself당연한소리
    Token(char, char, int); // 2-char token(e.g. <=) & its type(e.g.LE)2개세트로 오는데 하나로 치는것들
    Token(char*, int, int); // operand with its length & type(defaulted to ID) 더 긴것들, 식별자등등
    //생성자들

    bool IsOperand(); // true if the token type is ID or NUM 토큰이 식별자 혹은 숫자인지 여부확인
    int type; // ascii code for 1-char op; predefined for other tokens아스키값으로 판단해서 미리 토큰이 뭔지
    char* str; // token value 토큰값
    int len; // length of str 문자열길이
    int ival; // used to store an integer for type NUM; init to 0 for ID
};


using namespace std;
ostream& operator<<(ostream&, Token t);
Token NextToken(Expression&, bool); // 2nd arg = true for infix expression

#endif