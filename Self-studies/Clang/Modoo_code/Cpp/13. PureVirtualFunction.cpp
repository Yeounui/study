#include <iostream>

class Animal {
  public:
    Animal() {}
    virtual ~Animal() {}
    virtual void speak() = 0; //pure virtual function
    // 반드시 override 되어야 함. Animal 객체 생성도, Animal의 해당 함수 호출도 불가능.
    // 이렇게 반드시 상속 되어야하는 클래스를 abstract class (추상 클래스)라 정의.
};

class Dog : public Animal {
  public:
    Dog() : Animal() {}
    void speak() override { std::cout << "왈왈" << std::endl; }
};

class Cat : public Animal {
  public:
    Cat() : Animal() {}
    void speak() override { std::cout << "야옹야옹" << std::endl; }
};

int main() {
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    dog->speak();
    cat->speak();
}