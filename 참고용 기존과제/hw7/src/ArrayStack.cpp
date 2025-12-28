#include "ArrayStack.h"
#include <cassert>

template<typename T>
ArrayStack<T>::ArrayStack() : top(-1), capacity(INITIAL_CAPACITY) 
{
    items = new T[INITIAL_CAPACITY]; 
}

template<typename T>
ArrayStack<T>::~ArrayStack()
{
    delete[] items; 
}

template <typename T>//비었나
bool ArrayStack<T>::is_empty() const {
    return top < 0;
}

template<typename T>
void ArrayStack<T>::push(const T& someItem)
{
    if (top >= (capacity - 1)) //배열이 꽉찼으면
    {
        int new_capacity = capacity + 3; //용량 3증가
        
        T* new_items = new T[new_capacity]; //새 배열 만들기
        
        for (int i = 0; i <= top; i++)
        {
            new_items[i] = items[i]; 
        }//전부복사
        
        delete[] items; //원래배열 없애기
        
        items = new_items; 
        capacity = new_capacity;//용량증가
    }
    
    top++; 
    items[top] = someItem; //아이템추가
} 


template <typename T>//빼기
bool ArrayStack<T>::pop() {
    bool result = false; 
    if (is_empty()) 
    {
        throw PrecondViolatedExcep("Stack is empty!"); 
    }
    else
    {
        result = true; 
        top--; 
    } 
    return result;

}


template <typename T>//맨위 보기
T ArrayStack<T>::peek() const 
{
    if (is_empty()) 
    {
        throw PrecondViolatedExcep("Stack is empty"); 
    }//비었으면 오류

    return items[top]; 
}

//clear는 이미 헤더파일에서 간단히 구현됨.