#include <iostream>
#include "list.h"

ostream& operator<<(ostream& os, IntList& il) {
    Node *ptr = il.first;
    while (ptr != NULL) {
        os << ptr->data << " "; ptr = ptr->link; }
        os << endl;
    return os;
}
void IntList::Push_Back(int e) {
    if (!first)
    first = last = new Node(e);
    else {
        last->link = new Node(e);
        last = last->link;
    }
}
void IntList::Push_Front(int e) { /* 작성 */ 

}
void IntList::Insert(int e) {
 //자유롭게 작성
 //Node 포인터 하나만으로도 리스트 순회 가능.
    if(!first){ /* 작성 */}
    else if(first->data >= e){ /* 작성 */ }
    else{/* 작성 */}

}


void IntList::Delete(int e) {
//자유롭게 작성
//Node 포인터 하나만으로도 리스트 순회 가능.
    if(first){
        if(first->data == e){ /* 작성 */ }
        else{ /* 작성 */ }
    }
}