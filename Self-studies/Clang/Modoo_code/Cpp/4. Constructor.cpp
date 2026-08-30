#include <iostream>
/* Constructor (생성자) : 객체 생성시 자동으로 호출되는 함수
** 1. 함수 이름과 클래스 이름이 동일. 이름이 대소문자까지 완전히 동일해야 함.
** 2. 반환 타입(Return Type)이 없음. void도 적으면 안 됨. 반환 타입 적는 칸 자체가 존재하지 않음.
**
** 3. const, volatile, static 한정자 붙이지 않음. */
class Date {
  int year_;
  int month_; // 1 부터 12 까지.
  int day_; // 1 부터 31 까지.

public:
  void SetDate(int year, int month, int date);
  void AddDay(int inc);
  void AddMonth(int inc);
  void AddYear(int inc);

  // 해당 월의 총 일 수를 구한다.
  int GetCurrentMonthTotalDays(int year, int month);

  void ShowDate();

  Date(int year, int month, int day) { // Constructor; 이름 동일, 반환 타입 없음.
      year_ = year;
      month_ = month;
      day_ = day;
    }
};

void Date::SetDate(int year, int month, int day) {
    year_ = year;
    month_ = month;
    day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month) {
    static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month != 2) {
        return month_day[month - 1];
    } else if (year % 4 == 0 && year % 100 != 0) {
        return 29; // 윤년
    } else {
        return 28;
    }
}

void Date::AddDay(int inc) {
    while (true) {
        // 현재 달의 총 일 수
        int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);
        // 같은 달 안에 들어온다면;
        if (day_ + inc <= current_month_total_days) {
            day_ += inc;
            return;
        } else {
        // 다음달로 넘어가야 한다.
        inc -= (current_month_total_days - day_ + 1);
        day_ = 1;
        AddMonth(1);
        }
    }
}

void Date::AddMonth(int inc) {
    AddYear((inc + month_ - 1) / 12);
    month_ = month_ + inc % 12;
    month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate() {
    // std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
    //          << " 일 입니다 " << std::endl;
    std::printf("오늘은 %4d 년 %2d 월 %2d 일 입니다\n", year_, month_, day_); // C++17까지. 혹은 <iomanip> 사용.

}

int main() {
    /* 생성자없이는 통과, 생성자 클래스 내 포함 시 에러.
    ** Date day;                  생성자 없이 SetDate로만 Date를 정의 시, 
    ** day.SetDate(2010, 1, 30);  인자 초기화(멤버 변수에 초기값 할당) 필수.
    ** day.ShowDate(); */
    Date day1(2011, 3, 1);        // 생성자 암시적 호출 방법 (implicit)
    day1.ShowDate();
    day1.AddDay(30);
    day1.ShowDate();
    std::cout << "--------------------------------" << std::endl;
    Date day2 = Date(2012, 3, 1); // 생성자 명시적 호출 방법 (explicit)
    day2.AddDay(2000);
    day2.ShowDate();
    day2.SetDate(2012, 1, 31); // 윤년
    day2.AddDay(29);
    day2.ShowDate();
    day2.SetDate(2012, 8, 4);
    day2.AddDay(2500);
    day2.ShowDate();
    return 0;
}