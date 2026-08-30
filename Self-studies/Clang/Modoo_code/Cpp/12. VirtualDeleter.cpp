#include <iostream>

class Parent {
  public:
    Parent() { std::cout << "Parent 생성자 호출" << std::endl; }
    virtual ~Parent() { std::cout << "Parent 소멸자 호출" << std::endl; }
    /* 소멸자에 virtual을 안 붙일 시 Derived의 소멸자가 호출되지 않아 메모리 누수 일어남.*/
};
class Child : public Parent {
  public:
    Child() : Parent() { std::cout << "Child 생성자 호출" << std::endl; }
    ~Child() { std::cout << "Child 소멸자 호출" << std::endl; }
};
int main() {
    std::cout << "--- 평범한 Child 만들었을 때 ---" << std::endl;
    {
        Child c;
    }
    std::cout << "--- Parent 포인터로 Child 가리켰을 때 ---" << std::endl;
    {
        Parent *p = new Child();
        delete p;
    }
}