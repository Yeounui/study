#include <stdio.h>

// const를 붙여 정의된 변수는 값을 수정할 수 없다.
int main() {
    const int a = 3; // const 선언 시 변수에 값 할당이 필수. (const int a; 불가)
    
    printf("%d", a);
    return 0;
}
