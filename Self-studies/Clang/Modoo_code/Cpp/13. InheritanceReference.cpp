#include <iostream>

class A {
  public:
    virtual void show() { std::cout << "Parent !" << std::endl; }
};
class B : public A {
  public:
    void show() override { std::cout << "Child!" << std::endl; }
};

void test(A& a) { a.show(); } // A 클래스 레퍼런스를 인자로 설정

int main() {
    A a;
    B b;
    test(a); 
    test(b); // "Child!" b는 B 클래스임에도 A 클래스를 상속받았기에 인자 전달 가능.

    return 0;
}