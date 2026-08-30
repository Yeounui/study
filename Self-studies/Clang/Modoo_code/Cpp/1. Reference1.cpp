#include <iostream>
int main() {
    int a = 3;
    int& another_a = a;
    /*Reference (참조자):
        포인터와 달리, 변수가 주소값을 매핑하는 것이 아닌, 컴파일러에게 한 변수에 두가지 이름이 있다고 안내함.
        another_a의 주소값와 a의 주소값은 같음. 그러나 주소값을 매핑하는 방식이 아님.
     **포인터와의 차이점.
        1. 레퍼런스는 선언과 동시에 어느 변수를 공유할 것인지 정의함. (불가: int& another_a;)
        2. 레퍼런스 정의 이후, 공유 변수 변경 불가. (모순[주소값 = 원소값]: &another_a = b;)
        3. 레퍼런스는 메모리 상에 존재 불가. (컴파일러는 a와 another_a를 동일 변수로 인식.) */
    another_a = 5; // another_a를 5로 새로 정의. -> 이름 a는 동일 변수를 공유 -> a 또한 5.

    std::cout << "a : " << a << std::endl;
    std::cout << "another_a : " << another_a << std::endl;
    return 0;
}