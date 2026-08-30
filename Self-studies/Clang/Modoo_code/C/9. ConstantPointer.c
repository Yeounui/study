/* 상수 포인터? */
#include <stdio.h>
int main() {
    int a;
    int b;
    const int* pa = &a; // 상수 포인터: 자료형(int) 고정

// *pa = 3;  // 올바르지 않은 문장
    pa = &b; // 올바른 문장

    return 0;
}