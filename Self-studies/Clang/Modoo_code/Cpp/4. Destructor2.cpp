// 소멸자 호출 확인
#include <string.h>
#include <iostream>

class Test {
  char c;

public:
  Test(char _c) {
    c = _c;
    std::cout << "생성자 호출 " << c << std::endl;
  }

  ~Test() { std::cout << "소멸자 호출 " << c << std::endl; }
};

void simple_function() { Test b('b'); }
int main() {
    Test a('a');
    simple_function();
}

/* 생성자 호출 a : main 함수 내, 인스턴스 생성 & 생성자 호출
** 생성자 호출 b : simple_function 함수 내, b 인스턴스를 생성 & 생성자 호출
** 소멸자 호출 b : simple_function 종료와 함께 simple_function 지역 인스턴스 b 소멸.
** 소멸자 호출 a : main 종료와 함께 main 내 인스턴스 a 소멸. */
