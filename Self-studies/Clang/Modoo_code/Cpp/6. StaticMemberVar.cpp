#include <iostream>
/* C: static 키워드가 선언된 지역변수는 범위 밖에서도 소멸되지 않고 현재 파일 내 코드 범위에서 남아있음. (5. Static.c 참고)
** C++: 개념 변화 = 클래스 전체의 관리자 역할
**    * 클래스 내 모든 인스턴스가 공유하는 변수/함수. -> 함수|변수값 변경가능.
        -> 한 클래스 내 인스턴스끼리 같은 함수|변수(동일 주소)를 사용.
**    * static 변수는 선언 할당 동시에 불가. static const의 경우엔 가능.
**    * 여러 쓰레드가 동시 수정 시 데이터 오염(Race Condition)이 발생 -> std::atomic|mutex로 선점하도록 설계 */
class Marine {
    static int total_marine_num;
    int hp;
    int coord_x, coord_y;
    bool is_dead;
    const int default_damage;
    
  public:
    Marine();                          // Default Constructor
    Marine(int x, int y);
    Marine(int x, int y, int default_damage);
    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);
    void show_status();
    ~Marine() { total_marine_num--; } // 소멸자에 static 변수 조작
};
// 클래스 내 Static 변수는 클래스 외부에서만 초기화 가능;
// 클래스 내부에서 선언 할당 동시에 하려면 const static.
int Marine::total_marine_num = 0;

Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
  total_marine_num++; // 생성자에 static 변수 조작
} 
Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
  total_marine_num++;
}
Marine::Marine(int x, int y, int default_damage)
  : coord_x(x),
    coord_y(y),
    hp(50),
    default_damage(default_damage),
    is_dead(false) {
  total_marine_num++;
}
void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
              << std::endl;
    std::cout << " HP : " << hp << std::endl;
    std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}
void create_marine() {
    Marine marine3(10, 10, 4);
    marine3.show_status();
}
int main() {
    Marine marine1(2, 3, 5);
    marine1.show_status();
    Marine marine2(3, 5, 10);
    marine2.show_status();
    create_marine();
    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());
    marine1.show_status();
    marine2.show_status();
}