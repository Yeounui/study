/* 열거형의 도입 */
#include <stdio.h>

enum { RED = 3, BLUE, WHITE,     BLACK }; // R: 3, B: 4, W: 5, B:6
/*enum 내 원소 순서대로 번호 매김. int 인자들을 묶어 일괄적으로 정의.
  정의 없이는 0부터 3까지. 그러나 추가로 RED = 3 정의하면 따로 정의되기 전까지 다음 자리가 1씩 늘어남.
enum { RED = 3, BLUE, WHITE = 3, BLACK }; // R: 3, B: 4, W: 3, B:4
  */
int main() {
    int palette = BLACK;
    printf("%d \n", palette);
    switch (palette) {
        case RED:
            printf("palette : RED \n");
            break;
        case BLUE:
            printf("palette : BLUE \n");
            break;
        case WHITE:
            printf("palette : WHITE \n");
            break;
        case BLACK:
            printf("palette : BLACK \n");
            break;
    }
}
