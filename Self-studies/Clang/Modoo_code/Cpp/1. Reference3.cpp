#include <iostream>

int main() {
    int x;
    int& y = x; // x에 대한 레퍼런스 y
    int& z = y; // 이 또한 x에 대한 레퍼런스 z; 참조자의 참조자(int&&) 혹은 포인터(int*&)는 허용 안됨.
    // 참조자를 사용 시 포인터의 & 와 * 가 필요 없기에, 깔끔한 코드 작성 가능.
    x = 1;
    std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
    y = 2;
    std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
    z = 3;
    std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
}

/* ( x 선언)   (할당/선언)   ( y 선언)      설명
** (int  *x)      *x =  y; (int  y)
** (int  *x)      *x = *y; (int *y)
** (int  *x)       x = &y; (int  y)
** (int   x)       x =  y; (int  y)
** (int   x)       x = *y; (int *y)
** (int  &x) int  &x =  y; (int  y)   -   &x의 선언과 동시에 할당
** (int  &x) int  &x = *y; (int *y)   -   
** (int **x)     **x =  y; (int  y)   -   **x y값으로 할당
** (int **x)      *x =  y; (int *y)   -   **x의 주소를 *y의 주소로 할당
** (int **x)      *x = &y; (int  y)   -   **x의 주소를  y의 주소로 할당
** (int **x)       x = &y; (int *y)   -   **x의 주소의 주소를 *y의 주소로 할당
** (int *&x) int *&x =  y; (int *y)   -   *y의 주소에 또 다른 이름 x을 선언.
** (int *&x)      *x =  y; (int  y)   -   x라는 또 다른 이름을 가진 포인터 변수에 y의 주소 할당.
** (int *&x)       x = &y; (int  y)   -   x라는 또 다른 이름을 가진 포인터 변수의 주소에 y라는 또 다른 이름의 가진 변수의 주소를 할당.
** (int  *x)       x = &y; (int &y)   -   레퍼런스 y의 주소를 *x의 주소에 할당.
** (int   x)       x =  y; (int &y)   -   레퍼런스 y가 참조 값을 x에 할당.
** (int ***x)...
*/