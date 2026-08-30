#include <stdio.h>

int main() {
    void *a; // a는 주소, a*은 값, 그러나 void 이므로 이 변수는 오직 주소만 가짐. 주소값 보관하기 위한 타입.
    double b = 123.3;

    a = &b; // a 주소에 b의 주소를 연결
    printf("%lf  \n", *(double *)a); // (double *)a = double *;
    printf("%lf  \n", b);

    return 0;
}