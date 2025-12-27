#include "post.h"
#include <iostream>
#include "ArrayStack.h"
using namespace std;
bool Token::operator==(char b) { return len == 1 && str[0] == b; }//서로다른 두 자료형을 비교가능하게 해준다. 
bool Token::operator!=(char b) { return len != 1 || str[0] != b; }//위의 반대

//토큰의 생성자
Token::Token() {}

Token::Token(char c) : len(1), type(c) {
    str = new char[1];
    str[0] = c;
} // default type = c itself

Token::Token(char c, char c2, int ty) : len(2), type(ty) {
    str = new char[2];
    str[0] = c;
    str[1] = c2;
}

Token::Token(char* arr, int l, int ty = ID) : len(l), type(ty) {
    str = new char[len + 1];//deep copy준비
    for (int i = 0; i < len; i++) str[i] = arr[i];//복사
        str[len] = '\0';//마지막 널
    if (type == NUM) {//숫자라면
        ival = arr[0] - '0';//아스키0과 차이만큼이 진짜 숫자값이니까
        for (int i = 1; i < len; i++) ival = ival * 10 + arr[i] - '0';//자릿수 맞춰주기 > 여기까지 하면 문자열이 진짜 숫자가 됨
    } else if (type == ID)//식별자라면
        ival = 0;//값이 없지
    else
    throw "must be ID or NUM";
}

bool Token::IsOperand() { return type == ID || type == NUM; }

ostream& operator<<(ostream& os, Token t) {
    if (t.type == UMINUS)
    os << "-u";
    else if (t.type == NUM)
    os << t.ival;//아까만든 실제값을 써라
    else
    for (int i = 0; i < t.len; i++) os << t.str[i];//os에 한칸씩 추가
    os << " ";//항상 한칸띄어쓰기
    return os;
}//출력방법 정의

//이거는 an77같은거 처리할라고 필요함
bool GetID(Expression& e, Token& tok) {//레퍼런스를 사용해서 원본을 바꾼다
    char arr[MAXLEN];//임시
    int idlen = 0;
    char c = e.str[e.pos];
    if (!(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')) return false;//처음이 소문자거나 대문자가 아니면 false반환
    arr[idlen++] = c;
    e.pos++;
    while ((c = e.str[e.pos]) >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9') {
        arr[idlen++] = c;//두번째부터는 소문자거나 대문자거나 숫자이거나
        e.pos++;
    }
    arr[idlen] = '\0';//널로 포장
    tok = Token(arr, idlen, ID); // return an ID
    return true;
}

//숫자덩어리 처리용
bool GetInt(Expression& e, Token& tok) {
    if (e.pos >= e.len || !isdigit(e.str[e.pos])) {// 현재 위치가 문자열 끝이거나 숫자가 아니면 실패
        return false; 
    }

    int start_pos = e.pos;//시작위치 기억해야 덩어리 크기를 안다

    tok.ival = 0; //숫자니까 값초기화하고 시작

    while (e.pos < e.len && isdigit(e.str[e.pos])) {//숫자일때 계속 반복
        
        tok.ival = tok.ival * 10 + (e.str[e.pos] - '0');//아까처럼 진짜 값으로 만들기
        
        e.pos++;
    }
    
    tok.len = e.pos - start_pos; //길이
    
    tok.str = e.str + start_pos; //덩어리 시작위치
    
    tok.type = NUM;//타입은 숫자
    return true;
}

void SkipBlanks(Expression& e) {//빈칸 건너뛰기
    char c;
    while (e.pos < e.len && ((c = e.str[e.pos]) == ' ' || c == '\t')) {//공백혹은 탭이 올경우 넘기기
    e.pos++;
    }
}

bool TwoCharOp(Expression& e, Token& tok) {//두개짜리 연산자인지 확인한다.

    if (e.pos + 1 >= e.len) {//문자열 끝인지 여부 확인
        return false;
    }

    char c = e.str[e.pos];//지금위치
    char c2 = e.str[e.pos + 1];//한 칸 다음
    int op;

    if (c == '<' && c2 == '=')//if써서 맞는거 찾아서 반환
        op = LE;
    else if (c == '>' && c2 == '=') 
        op = GE;
    else if (c == '=' && c2 == '=') 
        op = EQ;
    else if (c == '!' && c2 == '=')
        op = NE;
    else if (c == '&' && c2 == '&')
        op = AND;
    else if (c == '|' && c2 == '|')
        op = OR;

    else {
        return false;
    } // 맞는 두 글자 토큰이 아니면 false

    tok = Token(c, c2, op);//묶어서 저장
    
    e.pos += 2; //두칸이동
    
    return true;
}

bool OneCharOp(Expression& e, Token& tok) {
 char c = e.str[e.pos];

 if (c == '-' || c == '!' || c == '*' || c == '/' || c == '%' || c == '+' || c == '<' || c == '>' || c == '(' || c == ')' || c == '=') {
 tok = Token(c);//생긴거 그대로 저장
 e.pos++;//한칸늘려
 return true;
 }

 return false;
}

Token NextToken(Expression& e, bool INFIX = true) {
    static bool oprrFound = true; // 종전에 연산자 발견되었다고 가정.
    Token tok;
    SkipBlanks(e); //공백없는데까지 이동

    if (e.pos == e.len) { // No more token left in this expression
        if (INFIX) oprrFound = true;
        return Token('#');
    }
    if (GetID(e, tok) || GetInt(e, tok)) {
        if (INFIX) oprrFound = false;
        return tok;
    }
    if (TwoCharOp(e, tok) || OneCharOp(e, tok)) {
        if (tok.type == '-' && INFIX && oprrFound) // operator 후 -발견
            tok = Token('-', 'u', UMINUS); // unary minus(-u)로 바꾸시오
        if (INFIX) oprrFound = true;
        return tok;
    }
 throw "Illegal Character Found";
}

int icp(const Token& t) { // in-coming priority 우선순위 정하기
    int ty = t.type;
    
    switch (ty) {
        case '(':
            return 0;

        case UMINUS:
        case '!':
            return 1;

        case '*':
        case '/':
        case '%':
            return 2;

        case '+':
        case '-':
            return 3;

        case '<':
        case '>':
        case LE:
        case GE:
            return 4;

        case EQ:
        case NE:
            return 5;

        case AND:
            return 6;

        case OR:
            return 7;

        case '=':
            return 8;

         case '#':
            return 9;
            
        default:
            return -1; 
    }
}

int isp(const Token& t)  // in-stack priority
{
    int ty = t.type; 
    
    switch (ty) {
        
        case '(':
        case '#':
        case '=':
            return 9;

        case UMINUS:
        case '!':
            return 2;

        case '*':
        case '/':
        case '%':
            return 2; 

        case '+':
        case '-':
            return 3; 

        case '<':
        case '>':
        case LE:
        case GE:
            return 4;

        case EQ:
        case NE:
            return 5; 

        case AND:
            return 6; 

        case OR:
            return 7;

        default:
            return -1;
    }
}

void Postfix(Expression e) {

    ArrayStack<Token> op_stack;//스택 생성

    Token bottom_marker('#');//바닥 깔아두기
    op_stack.push(bottom_marker);

    Token tok = NextToken(e, true);//첫번째 토큰넘기기

    // 4. 메인 루프: '#' 토큰(입력 끝)을 만날 때까지 반복합니다.
    while (tok != '#') { //끝이나기 전까지 반복


        if (tok.IsOperand()) {//token이 피연산자인경우
            std::cout.write(tok.str, tok.len);//문자열출력
            std::cout << " ";//공백도 출력
        } 
        
        else if (tok == ')') { // token 이 ')'인 경우 

            while (op_stack.peek() != '(') { //'('아니면 계속 반복
                Token t = op_stack.peek();
                std::cout.write(t.str, t.len);
                std::cout << " ";
                op_stack.pop();
            }
        
            op_stack.pop(); //(는 추가안하고 버려
        }
        
        
        else { // 그 외의 경우
            
            while (isp(op_stack.peek()) <= icp(tok)) {//이걸 위해서 icp, isp의 숫자를 만들었다. 
                //스택에 들어가 있는 기존isp가 새로 들어오는 icp보다 우선순위가 높으면 pop(원래놈이 새로운놈보다 쌔면 나온다)
                Token t = op_stack.peek();
                std::cout.write(t.str, t.len);
                std::cout << " ";
                op_stack.pop();
            }

            op_stack.push(tok);
        }

        tok = NextToken(e, true);

    }

    while (op_stack.peek() != '#') {//바닥보이기 전까지 전부 뽑아내기
        Token t = op_stack.peek();
        std::cout.write(t.str, t.len);
        std::cout << " ";
        op_stack.pop();
    }

    std::cout << std::endl;//다음줄로....
}