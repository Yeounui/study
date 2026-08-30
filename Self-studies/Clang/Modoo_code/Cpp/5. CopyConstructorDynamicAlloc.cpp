#include <string.h>
#include <iostream>
/* Shallow Copy vs Deep Copy
** 복사 생성자 정의하지 않을 시, 컴파일러가 멤버 변수를 1:1로 그대로 복사하는 기본 복사 생성자를 자동으로 생성. => 얕은 복사
** 하지만 클래스 내부에 포인터 변수가 있거나 동적 할당(new)을 사용 시, 기본 복사 생성자는 주소값을 복사하기에 두 객체가 같은 메모리를 가리킴
** -> 에러 발생. -> 직접 복사 생성자를 만들어서 메모리 할당 구현 필수. => 깊은 복사 */

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
Photon_Cannon::Photon_Cannon(int x, int y) {
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = NULL;
}
Photon_Cannon::Photon_Cannon(const Photon_Cannon &pc) {
    std::cout << "복사 생성자 호출! " << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;

    name = new char[strlen(pc.name) + 1]; //Deep Copy
    strcpy(name, pc.name);
}
Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name) {
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = new char[strlen(cannon_name) + 1]; //Deep Copy
    strcpy(name, cannon_name);
}
Photon_Cannon::~Photon_Cannon() {
// 0이 아닌 값은 if 문에서 true 로 처리
// if(name)는 곧 if(name != 0)과 동일한 의미.
// if 문에서 한 개의 phrase일 경우 중괄호 생략 가능.
if (name) delete[] name;
}
void Photon_Cannon::show_status() {
    std::cout << "Photon Cannon :: " << name << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
    << std::endl;
    std::cout << " HP : " << hp << std::endl;
}
int main() {
    Photon_Cannon pc1(3, 3, "Cannon");
    Photon_Cannon pc2 = pc1;
    /*  복사 생성자 없이는 pc2 = pc1 에서 pc1과 pc2는 같은 메모리를 참조함.
        그렇기에 main 함수가 종료되며 pc1의 객체들 또한 소멸되는데
        이때 동적 할당된 pc1의 name에 대한 메모리도 해제되어 다음에 pc2의 객체가
        소멸되려할 때 메모리의 주소를 찾을 수 없으므로 오류 발생
        그렇기에 깊은 복사를 가능케 하는 복사 생성자를 통해,
        다른 메모리 주소에 같은 값을 할당시켜, 나중에 미리 해제가 되어 있지 않게 한다.
    */
    pc1.show_status();
    pc2.show_status();
}