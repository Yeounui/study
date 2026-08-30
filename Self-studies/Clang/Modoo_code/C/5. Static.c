/* 정적 변수의 활용 */
#include <stdio.h>

int function() {
    static int how_many_called = 0;
    /* static 키워드가 선언된 지역변수는 범위를 벗어나더라도 해제되지 않음.
     * 그러나 접근 범위는 현재 c 파일에 한정됨. extern 키워드로 불러올 수 없음.
        1. 선언된 함수|변수는 파일 내부에서만 사용 (보안/은닉).
        2. Naming Collision 사고 방지.
    
     C++에서는 개념 변화 = 클래스 전체의 관리자 역할
     * 클래스 내 모든 인스턴스가 공유하는 변수/함수. -> 함수|변수값 변경가능.
        -> 한 클래스 내 인스턴스끼리 같은 함수|변수(동일 주소)를 사용.
     * static 키워드는 일반 멤버 변수와 사용 불가능. -> 클래스에서 노출불가.
     * 여러 쓰레드가 동시 수정 시 데이터 오염(Race Condition)이 발생 -> std::atomic|mutex로 선점하도록 설계
    */
    how_many_called++;
    printf("function called : %d \n", how_many_called);
    return 0;
}
int function2() {
    static int how_many_called = 0;
    
    how_many_called++;
    printf("function 2 called : %d \n", how_many_called);
    return 0;
}
int main() {
    function();
    function2();
    function();
    function2();
    function2();
    function2();
    function();
    function();
    function2();
    return 0;
}
