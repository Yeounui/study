#include <iostream>
/* 함수 인자 레퍼런스(1. Reference2.cpp)와 클래스 멤버함수 레퍼런스 비교
** int access_x(int &x) { return x; }
**
** class A {
**   public:
**     int x;
**     
**     A(int c) : x(c) {}
**
**     int& access_x() { return x; };
** };
**
** int main() {
**     A a(5);
**     int b = 5;
**
**     int& c = a.access_x();
**     c = 4;
**     std::cout << a.x << std::endl; // 4
**
**     int d = access_x(b);
**     d = 4;
**     std::cout << b << std::endl;  // 5
** };
*/
class A {
    int x;
  public:
    A(int c) : x(c) {} // `생성자 이름 : var1(arg1), var2(arg2), ... {}` 5. InitializerList.cpp 참조
    
    int& access_x() { return x; } // x의 레퍼런스 반환
    int  get_x()    { return x; } // x 반환
    void show_x() { std::cout << x << std::endl; }
};

int main() {
    A a(5);
    a.show_x();

    int& c = a.access_x(); // 멤버 변수 a.x가 또 다른 이름 c를 갖게 됨.
    c = 4;
    a.show_x(); // c가 4를 재할당 받았으므로 또 다른 이름인 a.x도 4를 재할당 받음. 따라서 a.show에서 4 출력.
    
    int d = a.access_x(); // d는 참조가 가리키는 실제 값 a.x를 복사해서 할당받음.
    d = 3;
    a.show_x(); // 그러나 a.x의 복사만 일어나게 되어 x값은 그대로 4.
    
/*  아래는 오류
**  int& e = a.get_x(); x 반환에 대한 임시 변수 생성, 임시 변수가 get_x 함수가 종료와 함께 소멸되며 댕글링 레퍼런스. -> 에러
**  e = 2;
**  a.show_x();
*/

    int f = a.get_x();
    f = 1;
    a.show_x();
}