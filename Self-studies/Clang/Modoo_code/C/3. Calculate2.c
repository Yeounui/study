/* 비트 연산 */
#include <stdio.h>

int main() {
    int a = 0xAF;           //         10101111
    int b = 0xB5;           //         10110101

    printf("%x \n", a & b); // a & b = 10100101 AND
    printf("%x \n", a | b); // a | b = 10111111 OR
    printf("%x \n", a ^ b); // a ^ b = 00011010 XOR
    printf("%x \n", ~a);    // ~a    = 01010000 INVERT
    printf("%x \n", a << 2);// a << 2= 1010111100 (int: 4 byte; 00000000 00000000 00000010 10111100) 
    printf("%x \n", b >> 3);// b >> 3= 00010110   (int: 4 byte; 00000000 00000000 00000000 00010110)

    return 0;
}
