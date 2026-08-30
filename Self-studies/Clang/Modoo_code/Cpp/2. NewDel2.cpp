/* new 로 배열 할당하기 */
#include <iostream>

int main() {
    int arr_size;

    std::cout << "array size : ";
    std::cin >> arr_size;

    int *list = new int[arr_size]; // C는 변수 선언이 실행 코드(값 대입과 함수 호출) 전에 선행되어야 하지만 C++은 이후에도 변수 선언 가능.
    for (int i = 0; i < arr_size; i++) {
        std::cin >> list[i];
    }
    for (int i = 0; i < arr_size; i++) {
        std::cout << i << "th element of list : " << list[i] << std::endl;
    }
    delete[] list; // new type[]이면 delete[]으로 해제.
    
    return 0;
}
/*
array size : 5
9
6
0
6
2

0th element of list : 9
1th element of list : 6
2th element of list : 0
3th element of list : 6
4th element of list : 2
*/