#include <stdio.h>
#include <malloc.h>

void main() {
	// 처음에 사용자가 숫자 몇개를 입력할지 결정한다.
	// 사용자가 입력한 숫자를 모두 저장한다.
	// 저장된 합계를 출력한다.
	int count; // 사용자가 입력할 갯수
	int* p;
	int hap=0;
	printf("몇개?"); scanf("%d", &count);
	// int numAry[count];
	p =  (int*) malloc(sizeof(int)*count);  // 동적 메모리 할당
	for (int i = 0; i < count; i++) {
		printf("%d번:",i);  scanf("%d", &p[i]);
	}
	// 합계
	for (int i = 0; i < count; i++) {
		hap += p[i];
	}
	printf("합계==> %d", hap);
	free(p);  // 메모리 해제
}