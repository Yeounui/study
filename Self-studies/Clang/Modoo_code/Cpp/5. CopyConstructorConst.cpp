#include <string.h>
#include <iostream>
/* Copy Constructor (복사 생성자):
** 1. Constructor 중 하나이므로,
**      1. 함수 이름이 클래스 이름과 반드시 동일.
**      2. 반환 타입(Return Type)이 없어야 함. (void도 불가)
** 2. 매개 변수로 자신과 같은 클래스의 Reference를 받음.
**      '&' 없이 값으로 매개변수를 할당 시, 함수 호출 후 인자 할당 과정에서 또다시 복사본을 만들기 위해 복사 생성자가 호출.
**      => 복사 생성자를 실행하기 위해 복사 생성자를 무한히 반복 호출하여 컴파일 에러가 발생.
** 3. const 한정자 (사실상 표준)
**      문법적 필수는 아님, 그러나 미사용 시 임시 객체(Cpp/1. Reference5.cpp 참조; 컴파일 시 에러)나 원본 내 상수(const) 값을 사용 불가.
**      원본의 데이터 보호와 원본 내 모든 멤버 변수의 복사를 가능케 하기 위해 const를 붙이는 게 관례.
** 4. 다른 추가 매개변수가 있을 시, 모두 기본값(Default Argument)이 지정되어야 함.
**      복사 생성자는 원본 객체만 넘겨주어도 호출이 가능해야 함. 인자를 따로 명시하지 않아도 값이 채워지도록 기본값이 설정 필수.
**
** 포인터를 매개변수로 받는 함수는 C++에서 '복사 생성자'로 인정하지 않음.
** 매개 변수(Parameter): 함수 정의 시 할당 값을 보관하기 위한 변수
** 인자 (Argument): 함수 '호출' 시 실제 전달된 값 혹은 변수
*/
class Photon_Cannon {
  int hp, shield;
  int coord_x, coord_y;
  int damage;
  char *name;
public:
  Photon_Cannon(int x, int y);
  Photon_Cannon(int x, int y, const char *cannon_name);
  Photon_Cannon(const Photon_Cannon &pc);
  ~Photon_Cannon();
  
  void show_status();
};
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
    /*  const instance: 인자 초기화 가능, 하지만 인자 자료형(Photo_Cannon) 고정 (C/9. ConstantPointer.c, Cpp/1. Reference2.cpp 참조)
    **  문법적으로 필수가 아니나, 원본 객체 데이터 보호(원본 상수 편집 X)와 원본의 모든 멤버 변수를 받아 쓸 수 있게 관례적 사용.
    **  함수 인자를 변화시키지 않는다면 const를 붙여주는 게 좋음. */
    std::cout << "복사 생성자 호출 !" << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
}
Photon_Cannon::Photon_Cannon(int x, int y) {
    std::cout << "생성자 호출 !" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
}
void Photon_Cannon::show_status() {
    std::cout << "Photon Cannon " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
              << std::endl;
    std::cout << " HP : " << hp << std::endl;
}
int main() {
    Photon_Cannon pc1(3, 3);
    Photon_Cannon pc2(pc1); // pc1의 인자를 가져와서 pc2에 새롭게 할당.
    Photon_Cannon pc3 = pc2;

    pc1.show_status();
    pc2.show_status();
}