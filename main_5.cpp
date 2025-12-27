#include <stdlib.h>
#include <stdio.h>

void Test(int *a)
{
	*a = 500;
}


int main()
{
	// 포인터 변수
	// 자료형 + 변수명
	int* pInt = nullptr;

	// 주소를 저장
	char* pChar = nullptr;
	short* pShort = nullptr;

	// 포인터 변수의 크기는 8 byte 이다 (64 bit 운영체제 한정)
	int iSzie = sizeof(pInt);

	int i = 0;
	pInt = &i; // & 는 주소값을 의미
	pInt += 1; // 100에서 시작했다면 104번째 주소값을 의미, &pInt +=1 라면 운영체제 단위만큼 증가 (주소위치 의미, 잘 안쓰임)

	// pInt 는 int* 변수이기 때문에 가리키는 곳을 int 로 해석
	// 따라서 주소값을 1 증가하는 의미는 다음 int 위치로 접근하기 위해서 sizeof(int) 단위로 증가

	// 포인터와 배열
	// 배열의 특징: 
	// 1. 10묶음의 메모리가 연속적
	// 2. 배열의 이름은 배열의 시작 주소
	int iArr[10] = {}; // int 10 묶음 선언, 전부 다 0으로 초기화

	iArr; // iArr 이란 배열의 이름이 곧 배열 주소

	iArr +1; // 실제론 4가 더해짐 (주소가 4 이동, int 이기에)
	
	// int 단위로 접근
	* (iArr + 0) = 10; // iArr[0] = 10;
	* (iArr + 1) = 10; // iArr[1] = 10; 주소값에 4 byte 떨어진 곳으로 가서 대입해라

	int a = 100;
	Test(&a); // 주소 값이 아니면 500, 포인터 개념이 들어가면 500
	printf("출력: %d\n", a);
	//scanf_s("%d", &a);


	// const
	// 상수화, 값이 바뀔 수 없는 상태
	// volatile 없다면 상수이기 때문에 레지스터 메모리에 저장해서 100을 계속 쓸 수 있음
	// 위의 말이 곧 컴파일러 최적화
	// volatile은 휘발성을 의미하며 메모리에 직접 접근해서 값을 읽어와라 라는 의미
	volatile const int cint = 100; // volatile : 컴파일러 최적화 방지

	// l-value : 변수, 값이 바뀔 수 있는 상태 
	// r-value : 상수, 값이 바뀔 수 없는 상태

	// 아래의 코드는 말이 안되는 코드
	pInt = (int*)&cint;
	*pInt = 300; // const int cint = 100; -> 300 으로 변경 가능 (volatile 때문에 가능)
	printf("출력: %d\n", cint);



	return 0;
 }
