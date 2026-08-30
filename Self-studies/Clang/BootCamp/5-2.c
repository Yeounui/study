#include <stdio.h>

void main() {
	char str[100];  // 파일에서 한줄 읽어온 거 저장
	FILE *rfp, *wfp;  // Read File Pointer

	// 파일 열기
	rfp = fopen("./source.txt", "r");
	wfp = fopen("./output.txt", "w");

	// 파일 처리하기(읽거나 쓰거나)
	while (1) {
		fgets(str, 100, rfp);
		fputs(str,wfp);
		if (feof(rfp)) // End Of File
			break;
	}
	printf("---끝 ---");

	// 파일 닫기
	fclose(rfp);
	fclose(wfp);

}