#include <iostream>

#include "Arr.h"


// 변수
// 지역 (스택)
// 전역, 정적, 외부 (데이터)

// 메모리 영역 구분
// 스택 영역 (지역 변수)
// 데이터 영역 (전역 변수, static 변수)
// ROM 영역 (상수)
// 힙 영역 (동적 할당)


// int 10묶음짜리 (40 byte) 자료형
typedef struct _tagSt
{
	int iArr[10]; // 아래와 마찬가지로 parameter 자리에 변수 입력 불가능
};


int main()
{
	// 힙 영역에 메모리 할당
	// parameter : 할당할 메모리 크기 (byte 단위)
	// pInt 는 스택, malloc 로 할당된 메모리는 힙 영역
	int* pInt = (int*)malloc(100);

	malloc(4); // 힙 메모리에 4 byte 할당 후 주소 반환

	// 동적 할당
	// 1. 런타임 중에 대응 가능
	// 2. 사용자가 직접 관리해야 함 (할당, 해제)

	int iInput = 0;
	scanf_s("%d", &iInput);

	int* pInt = nullptr;

	if (100 == iInput)
	{
		pInt = (int*)malloc(100);
	}

	if (nullptr != pInt)
	{
		free(pInt); // free 함수: 힙 메모리 해제
	}
	

	// 가변배열
	int a = 100;

	int iInput = 0;
	scanf_s("%d", &a);

	// 배열 개수를 선언할 때는 변수를 사용할 수 없음
	//int arr[a] = {}; // 불가능


	// 객체 (Instance)
	// 아래 int라는 자료형을 메모리에 올려놓은 것 (실제로 만들어 냄)
	// int a; // a는 객체

	tArr arr;


	return 0;
}
