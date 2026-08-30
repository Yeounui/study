#include <iostream>

class A {
  public:
    int a;
    
    A() { std::cout << "A 생성자 호출" << std::endl; }
};

class B {
  public:
    int b;

    B() { std::cout << "B 생성자 호출" << std::endl; }
};

class C : public B, public A { // B A 순서대로 동시 상속.
  public:
    int c;

    C(): A(), B() { std::cout << "C 생성자 호출" << std::endl; }
};

int main() { C c; }

/*
Diamond inheritance: diamond of death 방지.
A → B → D
  ↘ C ↗
  B, C로부터 A 성분을 D가 두 벌 상속 받았으므로 어느 쪽을
  상속해야할 지 모호해져 Ambiguity error 발생.

해결책: virtual 키워드 사용 시 A 성분을 한 벌만 받음.
class A {
  public:
    ...
};
class B : public virtual A {
    ...
};
class C : public virtual A {
    ...
};
class D : public B, public C {
    ...
};
*/