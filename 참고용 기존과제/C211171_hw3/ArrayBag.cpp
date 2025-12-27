# include < algorithm >
# include < iostream >
# include < vector >
# include "ArrayBag.h"//arraybag.h를 자세히 설명할 예정

template <typename T>//입력값없을때 생성자, 기본용량 100사용
ArrayBag <T >::ArrayBag () : item_cnt (0) , max_items ( DEFAULT_CAPACITY ) {}

template <typename T>//입력받은 값으로 생성
ArrayBag<T>::ArrayBag(int capacity) : item_cnt(0), max_items(capacity) {}

template <typename T>//현재사이즈출력
int ArrayBag <T>:: get_current_size () const {
    return item_cnt;//아이템카운트 반환 
}

template <typename T>//비어있는지여부 출력
bool ArrayBag <T>:: is_empty () const {
    if(item_cnt ==0){
        return 1;//카운트0이면 빈가방 
    }
    else{
        return 0;
    }
}

template <typename T>//물건더하기
bool ArrayBag <T>:: add( const T& newEntry ) {
    
    bool notfull = (item_cnt < max_items);// 가방이 꽉 찼는지 확인
    if (notfull == 1) {
        // 자리가 있으면, 가방 끝에 새 아이템을 추가
        items[item_cnt] = newEntry;
        item_cnt++; //카운트하나증가
        return 1;
    }else{
        return 0;
    }

}

template <typename T>//물건제거 
bool ArrayBag <T>:: remove ( const T& anEntry ) {
    int index_to_remove = get_index_of(anEntry);//제거할 물품위치를 변수새로만들어서 받는다 
    bool can_remove = (is_empty() == 0) && (index_to_remove > -1);//용량이 0이 아니고 물품이 존재하면 제거가능

    if (can_remove == 1) {//지울 수 있다면
        items[index_to_remove] = items[item_cnt - 1];//덮어쓰기
        item_cnt--; // 아이템 개수 1 감소로 맨뒤칸은 쓸수있는상태
        return 1;
    }
    else{
        return 0;
    }
}

template <typename T>//비우기 
void ArrayBag <T>:: clear () {
    item_cnt = 0;//카운트만 0으로 바꿔도 됨 
}

template <typename T>//포함여부 확인 
bool ArrayBag <T>:: contains ( const T& anEntry ) const {
    if(get_index_of(anEntry) > -1){
        return 1;
    }else{
        return 0;
    }
}

template <typename T>//특정물품이 몇개인지 
int ArrayBag <T>:: get_frequency_of ( const T& anEntry ) const {

    int frequency = 0;//빈도카운트변수 
    for (int i = 0; i < item_cnt; i++){
        if (items[i] == anEntry) {
            frequency++;
        }
    }
    return frequency;

}

template <typename T>//벡터로 전환 
std :: vector<T> ArrayBag <T>:: to_vector () const {
    std::vector<T> result;
    for (int i = 0; i < item_cnt; i++) {
        result.push_back(items[i]);
    }
    return result;
}

template <typename T>//특정물품 인덱스 반환 
int ArrayBag <T >:: get_index_of ( const T& target ) const {
    for (int i = 0; i < item_cnt; i++) {
        if (items[i] == target) {
            return i; // 찾으면 바로 인덱스 반환
        }
    }
    return -1; // 끝까지 못 찾으면 -1 반환(다른함수에서도 이 값을 사용할거니까)
}

//bag끝

template <typename U>
std :: ostream & operator <<( std :: ostream & os , const ArrayBag <U >& bag ) {
std :: vector <U> items (bag . to_vector () ) ;
sort ( items . begin () , items . end () ) ;

for ( const U& item : items ) {
os << item << " ";
}
return os;
}

template <typename T>//합집합 
ArrayBag <T> union_bags ( const ArrayBag <T>& bag1 , const ArrayBag <T>& bag2 ) {
    ArrayBag<T> result;//결과로 반환할 벡터생성 
    std::vector<T> vec1 = bag1.to_vector();
    std::vector<T> vec2 = bag2.to_vector();//인자로 받은 두 arraybag의 벡터화

    for (const T& item : vec1) {
        result.add(item);
    }

    for (const T& item : vec2) {
        result.add(item);
    }
    return result;//다 넣은거 반환
}

template <typename T>//교집합 
ArrayBag <T> intersect_bags ( const ArrayBag <T >& bag1 , const ArrayBag <T >& bag2 ) {
    ArrayBag<T> result;
    std::vector<T> vec1 = bag1.to_vector();//bag1으로 반복을 돌릴예정이라 벡터화한다 

    for (const T& item : vec1) {
        // item이 bag2에도 있다 && result에 추가된 개수가 bag2에 있는 개수보다 적다면 추가
        if (bag2.contains(item) && (result.get_frequency_of(item) < bag2.get_frequency_of(item))) {
            result.add(item);
        }
    }
    return result;
}

template <typename T>//차집합 
ArrayBag<T> ArrayBag<T>::difference(const ArrayBag<T>& another_bag) const {//this로 호출한 bag자기자신과 인자로받은 anotherbag을 사용함 
    ArrayBag<T> result;
    for (int i = 0; i < item_cnt; i++) {
        result.add(items[i]);//자기자신을 복사해서 넣는다
    }

    for (int i = 0; i < another_bag.item_cnt; i++) {
        result.remove(another_bag.items[i]);//anotherbag에도 있는걸 뺀다
    }
    return result;
}

