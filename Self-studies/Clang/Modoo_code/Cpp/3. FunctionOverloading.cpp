#include <iostream>
/* 함수의 Overloading
** C++는 같은 이름을 가진 함수가 여럿 존재해도 허용. C는 오직 하나만 허용.
** 같은 이름의 여러 함수가 존재한 상태에서, 그 함수를 호출할 때, 함수 인자를 기준으로 일치하는 함수를 호출.
*/

/* 1. 인자의 자료형이 동일한 함수. */
/* 2. 인자의 자료형이 동일한 함수가 없는 경우, 형변환을 통해 일치하는 함수
    * char, unsigned char, short => int
    * unsigned short => 크기에 따라 int 혹은 unsigned int
    * float => double
    * enum => int              */
void print(int x) { std::cout << "int : " << x << std::endl; }
void print(char x) { std::cout << "char : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }
/* 3. 좀더 포괄적인 형변환을 통해 일치하는 함수.
    * 임의의 numeric type => 다른 numeric type으로 변환. (ex) float -> int)
    * enum => 임의의 numeric type으로 변환. (ex) enum -> double)
    * pointer type 혹은 numeric type 0 => pointer type이나 numeric type으로 변환
    * pointer => void pointer
    4. 유저 정의된 type 변환으로 일치하는 것 ()
    5. 오류로 판단.              */

int main() {
    int a = 1;
    char b = 'c';
    double c = 3.2f; /* 함수 print(double x)가 없을 시, 임의의 numeric type => 다른 numeric type으로 변환
                        => int 인자 함수와 char 인자 함수 둘 모두 우선 순위가 같기에 오류가 남. */
    print(a);
    print(b);
    print(c);
    
    return 0;
}
