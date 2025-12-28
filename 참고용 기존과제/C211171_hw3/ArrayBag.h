# ifndef ARRAY_BAG_H//만약 arraybag이 정의되지않은 헤더이름이면
# define ARRAY_BAG_H//arraybag이라는 이름의 헤더를 정의할거다
# include < iostream >
# include < vector >


//ArrayBag클래스생성
template <typename T>//어떤타입올지 모르니까 템플릿사용
class ArrayBag {

private ://private변수 설정
static const int DEFAULT_CAPACITY = 100;//기본용량 100으로 설정 
T items [ DEFAULT_CAPACITY ];//디폴트용량의 크기를 가지는 배열 
int item_cnt ;//아이템카운트변수생성
int max_items ;//맥스아이템변수생성
int get_index_of (const T&) const ;//특정 아이템의 인덱스 확인


public ://public변수 설정
ArrayBag () ;//생성자
ArrayBag (int) ;//정수값 입력시 생성자
int get_current_size () const ;//현재크기확인 
bool is_empty () const ;//비어있는지여부확인
bool add( const T&) ;//물건추가
bool remove ( const T&) ;//물건제거
void clear () ;//가방비우기
bool contains ( const T&) const ;//물건포함여부확인
int get_frequency_of ( const T&) const ;//물건갯수반환
std::vector <T> to_vector () const ;//벡터로반환


template <typename U>//출력연산자인데 완벽하게 이해하지는 못함 cout을 대체한다는게 정확히 무슨뜻이지
friend std :: ostream & operator << ( std :: ostream & , const ArrayBag <U>&) ;

template <typename U>//합집합과 프렌드선언
friend ArrayBag <U> union_bags ( const ArrayBag <U>& , const ArrayBag <U>&) ;

template <typename U>//교집합과 프렌드선언
friend ArrayBag <U> intersect_bags ( const ArrayBag <U>& , const ArrayBag <U>&) ;

ArrayBag <T> difference ( const ArrayBag <T >&) const ;//차집합

//클래스생성종료
};




template <typename T>//합집합선언
ArrayBag <T> union_bags ( const ArrayBag <T>& , const ArrayBag <T>&) ;
//인자를 템플릿타입의 배열 두개를 별명붙여서 쓸건데 걔네 원본은 안건들이고 사용할거다 그리고 별명은 나중에 붙인다

template <typename T>//교집합선언
ArrayBag <T> intersect_bags ( const ArrayBag <T>& , const ArrayBag <T>&) ;

# include "ArrayBag.cpp"//이 헤더파일의 구현방식과 세부내용은 다른파일에서 가져와라
# endif//맨처음if와 한쌍