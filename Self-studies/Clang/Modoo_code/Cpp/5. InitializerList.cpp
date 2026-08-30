#include <iostream>

class Marine {
    int hp;
    int coord_x, coord_y;    
    bool is_dead;

    const int default_damage;
public:
    Marine(); // 기본 생성자
    Marine(int x, int y);
    Marine(int x, int y, int default_damage);

    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);
    void show_status();
};
//초기화 리스트 (initializer list):
//`생성자 이름 : var1(arg1), var2(arg2) {}`
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}
/* 동일한 표현:
** Marine::Marine() {
**   hp = 50;
**   coord_x = coord_y = 0;
**   is_dead = false;
**   const int default_damage = 5;
** } */
Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}
/* Marine::Marine(int coord_x, int coord_x)
**    : coord_x(coord_x), coord_y(coord_x), ...
** 초기화 리스트에선 멤버 변수와 멤버 함수의 인자 이름이 동일해도 문제 없음,
** 그러나 생성자에선 불가능 ex) coord_x = coord_x >>> 오류
** 보통의 생성자는 디폴트 생성자 호출 후 대입 수행. (예: int a; a = 10)
** 초기화 리스트는 변수 생성과 인자 대입 동시 수행. (예: int a = 10)
** 레퍼런스와 상수는 '생성과 동시에 초기화됨'
** 따라서 클래스 내 레퍼런스 변수나 상수를 넣고 싶다면 생성자에서 무조건 초기화 리스트를 사용해야함. **/
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
}
int main() {
    Marine marine1(2, 3);
    Marine marine2(3, 5);
    marine1.show_status();
    marine2.show_status();
}