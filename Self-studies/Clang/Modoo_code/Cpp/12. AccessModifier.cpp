#include <iostream>
#include <string>

class Base {
  protected: //public, private의 중간 수준; 상속 클래스에서만 접근 가능, 그 외 외부 접근 불가.
    std::string parent_string;

  public:
    Base() : parent_string("기반") { std::cout << "기반 클래스" << std::endl; }
    
    void what() { std::cout << parent_string << std::endl; }
};
class Derived : public Base {
    /*  상속 문법: class "parent_class" : <Access_Modifier> "child_class"
        public으로 상속: 부모 클래스의 접근 지시자들에 영향 없이 그대로 작동.
        (public, protected, private) => (public, protected, private)
        protected로 상속:
        (public, protected, private) => (protected, protected, private)
        private으로 상속:
        (public, protected, private) => (private, private, private)
    */
    std::string child_string;

  public:
    Derived() : Base(), child_string("파생") {
      std::cout << "파생 클래스" << std::endl;
      what();
      /* Overriding: Derived의 what 함수가 Base의 what 함수를 오버라이딩.
         하지만 각각의 what 함수는 서로 다른 함수로 취급. */
      parent_string = "바꾸기"; // protected 내 parent_string은 상속된 클래스에서 접근 가능. (private였으면 불가.)
    }

    void what() { std::cout << child_string << std::endl; } 
};
int main() {
    std::cout << " === 기반 클래스 생성 === " << std::endl;
    Base p;

    std::cout << " === 파생 클래스 생성 === " << std::endl;
    Derived c;

    return 0;
}