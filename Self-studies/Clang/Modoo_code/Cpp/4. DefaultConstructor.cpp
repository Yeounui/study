#include <iostream>
/* Default Constructor (디폴트 생성자): 인자를 가지고 있지 않은 생성자.
** 클래스 내 생성자 중 아무도 명시적으로 정의하지 않았을 시 자동 인자 초기화.
** C++11부터 디폴트 생성자를 사용하도록 명시 가능.
** 
**  class Date {
**    int year_ = 2026; // C++11부터는 멤버변수 선언과 동시에 초기화 가능
**    int month_ = 1;
**    int day_ = 1;
**  public:
**    Date() = default; // 컴파일러에게 기본 생성자를 명시적으로 요청
**
**    Date(int year, int month, int day) { year_ = year; month_ = month; day_ = day; }
**  };
**
**  int main() {
**    Date day1(2011, 3, 1);
**    Date day2;        // 컴파일러가 만든 default 생성자 호출; 2026, 1, 1로 초기화
**  } */
class Date {
    int year_;
    int month_; // 1 부터 12 까지.
    int day_; // 1 부터 31 까지.
    
public:
    void ShowDate();
    
    Date() { // 디폴트 생성자
        std::cout << "기본 생성자 호출!" << std::endl;
        year_ = 2012;
        month_ = 7;
        day_ = 12;
    }
    Date(int year, int month, int day) { 
        std::cout << "인자 3개인 생성자 호출!" << std::endl;
        year_ = year;
        month_ = month;
        day_ = day;
    }
};

void Date::ShowDate() {
    std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
    << " 일 입니다 " << std::endl;
}

int main() {
    Date day = Date(); // 디폴트 생성자 호출; A a()
                       // 인자가 없는 생성자를 호출하기 위해선 A a.
    Date day2(2012, 10, 31);

    day.ShowDate();
    day2.ShowDate();
    return 0;
}