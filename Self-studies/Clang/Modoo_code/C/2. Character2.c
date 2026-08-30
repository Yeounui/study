/* scanf 총 정리 */
#include <stdio.h>
int main() {
    char ch; // 문자
    /*
    한글은 2 바이트 이상을 차지하기 때문에 최대 1 바이트를 차지하는 char형
    변수인 ch 에 한글을 치면 오류
    */
    short sh; // 정수
    int i;
    long lo;
    float fl; // 실수
    double du;
    printf("char 형 변수 입력 : ");
    scanf("%c", &ch);
    printf("short 형 변수 입력 : ");
    scanf("%hd", &sh);
    printf("int 형 변수 입력 : ");
    scanf("%d", &i);
    printf("long 형 변수 입력 : ");
    scanf("%ld", &lo);
    printf("float 형 변수 입력 : ");
    scanf("%f", &fl);
    printf("double 형 변수 입력 : ");
    scanf("%lf", &du);
    printf("char : %c , short : %d , int : %d ", ch, sh, i);
    printf("long : %ld , float : %f, double : %f \n", lo, fl, du);
    return 0;
}

/*
scanf의 치명적 결함: scanf 함수(특히 문자열을 받는 %s)는 데이터 입력 시 "목적지 메모리의 크기가 얼마인지" 확인 안함.
buffer 보다 큰 데이터가 근처의 다른 데이터나 함수의 복귀 주소(Return Address)를 덮어 씌움.
함수 종료 시 공격자가 심어놓은 '셸(Shell) 실행 코드'로 점프하여 실행시킴. 혹은 메모리 내 인증 로직을 덮어씌워 무력화.

대안:
1. scanf_s (C11 표준 / MSVC 권장)
입력 크기를 인자로 직접 전달. 더 큰 데이터가 들어오면 아예 입력을 받지 않음.
char buf[10];
scanf_s("%s", buf, (unsigned int)sizeof(buf)); // 안전!

2. fgets (추천)
한 줄 단위로 읽음, 최대 크기를 지정 가능. -> 가장 안전하고 범용적.
fgets(buf, sizeof(buf), stdin); // 지정 크기만 읽음.

3. scanf에서 크기 제한.
scanf("%9s", buf); // 최대 9글자만 읽고 마지막은 \0를 위해 남겨둠
*/