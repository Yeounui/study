#include <iostream>

int change_val(int &p);

int main() {
    int number = 5;
    std::cout << number << std::endl;
    change_val(number); // 레퍼런스에 의해 p는 number와 같음.
    std::cout << number << std::endl;
}

int change_val(int &p) { // C에서는 포인터를 int *number 처럼 미리 선언 해야겠지만 C++에서는 레퍼런스의 사용으로 포인터 선언을 할 필요가 없다.
    p = 3;
    return 0;
}

/*  변수 number의 입장에서 동등한 C 코드. (10. PointerArgument.c 참고)
    C에서는 변수 '선언' 시 '&' 키워드 사용 불가능; 오로지 데이터 타입 변수의 주소값 '할당' 시에만 '&' 키워드 사용 가능.
    따라서 '외부 변수를 변화시키는 함수'를 만들 때 인자를 무조건 *<varname> 이런 식으로 줘야함.
    그러나 C++에서는 레퍼런스의 도입으로 키워드 '*'와 '&' 사이에 대응 관계가 만들어진다.
                   포인터 타입     데이터 타입
     인풋 정의 시:   int number    int number
     함수 정의 시:   *p            &p
     인자 할당 시:   &number       number
    
    #include <stdio.h>

    int change_val(int *p);         // 1. 함수 종료 이후에도 함수 내 변화를 변수에 반영 -> 주소값을 줘야함. 
    int main() {
        int number = 5;
        printf("%1d\n", number); //5 출력.
        change_val(&number);        // 4. 주소값을 함수인자에 '할당'하기에 '&' 키워드 사용.
        printf("%1d\n", number); //3 출력.
    }

    int change_val(int *p) {        // 2. '&' 키워드는 C에서 포인터 변수에 주소값을 할당 시에만 쓰이므로 '&' 대신 '*' 사용.
        *p = 3;                     // 3. pointer int를 변수로 받았으므로 '*' 사용.
        return 0;
    }
*/