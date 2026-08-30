#include <iostream>
#include <string>

class Base {
  std::string s;

  public:
    Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }
    void what() { std::cout << s << std::endl; }
    virtual void incorrect() { std::cout << "기반 클래스" << std::endl; }
    /*  virtual keyword: Dynamic binding (동적 바인딩) 지원: Complie 시 타입을 보고 결정.
        실제 객체 타입을 기준으로 함수 실행 => Complier에게 자식 클래스에게 재정의 될 수 있음을 알려줌.
        키워드가 붙은 함수를 virtual function (가상 함수)라 부름
        C++에서 가상함수가 존재하는 클래스에 대해 virtual function table(vtable, 가상 함수 테이블)이 생성
        함수가 실제 부모 유래인지 자식 유래인지 연결시키는 테이블로 저장*/
};
class Derived : public Base {
    std::string s;

  public:
    Derived() : Base(), s("파생") {}
    void what() { std::cout << s << std::endl; }
    void incorrect() override { std::cout << "파생 클래스" << std::endl; } 
    /* 자식 클래스에서 부모 클래스의 가상 함수를 오버라이드 하는 경우 override 키워드로 명시 가능*/
};
int main() {
    Base p;
    Derived c;

    Base* p_p = &p;
    Base* p_c = &c;
    

    std::cout << " === 기반 클래스 생성 === " << std::endl;
    p_p->incorrect();

    std::cout << " === 파생 클래스 생성 === " << std::endl;
    p_c->incorrect();

    std::cout << " === 포인터 버전 === " << std::endl;
    p_c->what(); // 기반
    //Derived지만, Derived는 Base로부터 상속 받았기에 Base*로 받을 시 p_c는 Base 클래스 포인터가 된다.
    //반대로 Base가 Derived*로 받아 Derived 클래스 포인터가 될 순 없다.

    std::cout << " === Base -> Derived 강제 형변환 === " << std::endl;
    Derived* p_gc = static_cast<Derived*>(p_c); // 파생
    //하지만 원래 Derived인 걸 아므로 강제 형변환으로 Base -> Derived 가능. (11. TypeCasting.cpp)
    //static_cast로 다운캐스팅이 허용되는 경우는 객체가 실제 그 파생 타입일 때 뿐
    //                검사_시점    안전성_확인     실패_시                            속도                          요구_조건
    // static_cast:   컴파일_타임  안함           조용히 UB (segfault 등)             빠름 (검사 없음)               없음
    // dynamic_cast:  런타임      객체_타입_확인   nullptr_반환(포인터)/예외_던짐(참조)  느림 (런타임에 타입 정보 확인)   대상 클래스에 virtual 함수가 최소 하나 존재
    p_gc->what();

    return 0;

}