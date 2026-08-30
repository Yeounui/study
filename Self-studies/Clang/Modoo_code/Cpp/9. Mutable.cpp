#include <iostream>
/*  Mutable: const 멤버 함수 내에서 해당 키워드를 가진 변수 변경 가능.
**  const 멤버 함수: '이 함수는 객체 내부 상태를 변경하지 않음.'
**  대부분 상수를 가진 읽기 작업 수행, 하지만 때때로 데이터를 가져와 새로 할당해야하는 경우가 있음.
**  예) 일반적으로 서버 메모리 캐쉬를 이용하지만, 없을 시 값을 데이터베이스에 요청해 받아와야 하는 경우,
**      const 멤버 함수 내 변수에 할당해야 하기에 mutable 사용
*/

class A {
    mutable int data_; // mutable

public:
    A(in data)  : data_(data) {}
    void DoSomething(int x) const {
        data_ = x; 
    }
    
    void PrintData() const {std::cout << "data: " << data_ << std::endl; }
};

int main() {
    A a(10);
    a.DoSomething(3); // const 함수 임에도 변수 할당 가능.
    a.PrintData();
}