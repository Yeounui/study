#include <stdio.h>

int maintain_arg(int pi) {
    printf("---- maintain_val 함수 안에서 ---- \n");
    printf("pi 의 값: %p \n", &pi);
    printf("pi 가 가리키는 값 : %d \n", pi);
    
    pi = 3;

    printf("---- maintain_val 함수 ---- \n");
    
    return 0;
} // i = maintain_val(int i);
int change_arg(int *pi) { //함수의 인자를 포인터로 받으면 외부에서 선언된 변수를 함수 내에서 조작 가능.
    printf("---- change_val 함수 안에서 ---- \n");
    printf("pi 의 값: %p \n", pi);
    printf("pi 가 가리키는 값 : %d \n", *pi);
    
    *pi = 3;

    printf("---- change_val 함수 ---- \n");
    
    return 0;
} // change_val(int &i);
int main() {
    int i = 0;

    printf("i의 주소값: %p \n\n", &i);
    printf("maintain_val 호출 이전 i 값: %d \n", i);
    maintain_arg(i);
    printf("maintain_val 호출 이후 i 값: %d \n\n", i);
    printf("change_val 호출 이전 i 값: %d \n", i);
    change_arg(&i); // 포인터 정수 값에 주소값을 할당해야하므로 '&i'
    printf("change_val 호출 이후 i 값: %d \n", i);

    return 0;
}