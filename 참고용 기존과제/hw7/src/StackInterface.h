#ifndef __STACK_INTERFACE__
#define __STACK_INTERFACE__
#include <stdexcept>
#include <string>

class PrecondViolatedExcep : public std::logic_error {
public:
 PrecondViolatedExcep(const std::string& message = "")
 : std::logic_error("Precondition Violated Exception: " + message) {}
};//오류메세지


template <typename T>
class StackInterface {
public:
 /**
 * Stack 이 비었는지 여부를 확인합니다.
 * @return 비었으면 true, 아니면 false
 */
 virtual bool is_empty() const = 0;

 /**
 * Stack 의 최상단에 새로운 아이템을 추가합니다
 * @post item 이 Stack 의 최상단에 추가됩니다.
 * @param item 추가할 아이템
 * 교재와 차이점: 더 추가할 수 없을 경우 용량을 늘리게끔 설정
 */
 virtual void push(const T& item) = 0;

 /**
 * Stack 의 최상단 아이템을 제거합니다.
 * @post 성공적으로 수행된다면, Stack 의 최상단 아이템이 제거됩니다.
 * @return 성공적으로 제거되었다면 true, 아니면 false
 */
 virtual bool pop() = 0;

 /**
 * Stack 의 최상단 아이템의 사본을 반환합니다.
 * @pre Stack 이 비어있지 않아야 합니다.
 * @post Stack 의 최상단 항목의 사본이 반환되고, stack 의 상태는 변하지
 * 않습니다.
 * @return Stack 의 최상단 아이템의 사본
 */
 virtual T peek() const = 0;

 /**
 * stack 의 모든 아이템을 제거합니다.
 * @post Stack 이 비어있게 됩니다.
 */
 virtual void clear() = 0;

  /**
 * 할당된 메모리를 해제하고, stack 을 소멸시킵니다.
 */
 virtual ~StackInterface() {}

};

#endif // __STACK_INTERFACE__
