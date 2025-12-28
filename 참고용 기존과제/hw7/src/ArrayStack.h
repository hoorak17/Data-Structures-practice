#ifndef __ARRAY_STACK__
#define __ARRAY_STACK__
#include "StackInterface.h"

template<typename T>
class ArrayStack : public StackInterface<T>
{
private:
    static const int INITIAL_CAPACITY = 5; 
    T* items;   // 스택 아이템을 저장할 포인터 
    int top;         
    int capacity; 

public:
    ArrayStack(); // 생성자
    virtual ~ArrayStack(); // 소멸자 (동적 할당 해제용)
    
    // StackInterface로부터 상속받은 함수들
    bool is_empty() const;

    void push(const T& item); // 용량 확장 기능이 추가됨

    bool pop();

    T peek() const;

    void clear() {top = -1;}
};

#include "ArrayStack.cpp"
#endif // __ARRAY_STACK__