/* 포인터 상수 */
#include <stdio.h>

int main() {

    int a;
    int b;
    
    int* const pa = &a; // 포인터 상수: pa가 a 변수의 주소값과 같음을 선언한 이후, 주소 변경 불가.
    printf("%p \n", &a);
    printf("%p \n", pa);
    *pa = 3;  // 올바른 표현
   //pa = &b; // 틀린 표현 - 주소값을 b 주소로 재할당할 수 없다.
    
   return 0;
}