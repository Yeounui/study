#include <iostream>

struct Position {
    int x;
    int y;
    char ch;
    inline void OutPosition();
    // inline 명시: 컴파일러에게 구조체 내 멤버 함수임을 명시하여 컴파일 시 함수를 구조체 내 넣어놓고 컴파일함. 인라인 결정은 컴파일러 재량.
    // 장점: 함수 호출 오버헤드를 줄임; 단점: 함수 코드 반복 삽입되어 코드 크기 증가.
};

inline void Position::OutPosition() { //
    std::cout << x << "," << y << std::endl;
    std::cout << ch << std::endl;
}

int main() {
    Position Here;
    Here.x=30;
    Here.y=10;
    Here.ch='A';
    Here.OutPosition();
    return 0;
}