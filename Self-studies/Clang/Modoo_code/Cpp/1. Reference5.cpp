#include <iostream>

/* Dangling Reference:
    함수 내의 변수를 레퍼런스를 통해 참조하였으나 함수가 종료됨에 따라 참조한 내부변수도 사라지게 되어 레퍼런스만 남아 오류 발생.

    int function() {
        int a = 5;
        return a;
    }

    int main() {
        int& c = function();
        //  레퍼런스 c에 function의 내부변수 a를 할당했지만,
        //  function 종료와 함께 내부변수 a도 해제 -> 레퍼런스 c에 지정된 변수가 없으므로 에러 발생.
        c = 2;
        return 0;
    }
*/

int function() {
    int a = 5;
    return a;
};
int main() {
    const int& c = function(); // 상수 레퍼런스(Constant Reference)에 값을 할당 받으면, 값을 수정할 수 없게 되므로 문제 없음.
    std::cout << "c : " << c << std::endl; 
    return 0;
}