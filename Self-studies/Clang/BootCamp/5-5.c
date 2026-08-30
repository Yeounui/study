#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

// 영상 크기 : 5x5 고정
#define height 5
#define width 5

//////////////////////////
/// 함수 선언부
void loadImage();
void displayImage(const char str[]);

//////////////////////////
/// 전역(Global) 변수부 <---> 지역(Local) 변수
unsigned char m_image[height][width];

//////////////////////////
/// 메인 코드부
void main() {
	loadImage();

}

//////////////////////////
/// 함수 정의부
void loadImage() {
	// Disk --> Memory (m_image)
	srand((unsigned int)time(0)); // 타이머 초기화
	for (int i = 0; i < height; i++) {
		for (int k = 0; k < width; k++) {
			m_image[i][k] = rand() % 256; // 0~255 사이의 랜덤값
		}
	}
	displayImage("원본 이미지");
}

void displayImage(const char str[]) {
	// Memory --> Monitor
	printf("** %s ** \n", str);
	for (int i = 0; i < height; i++) {
		for (int k = 0; k < width; k++) {
			printf("%3d ", m_image[i][k]);
		}
		printf("\n");
	}

}