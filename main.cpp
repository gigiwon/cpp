#include <stdio.h>

// 변수종류
// 1. 지역변수 (Local Variable)		: 함수 내부에 선언된 변수
// 2. 전역변수 (Global Variable)		: 함수 외부에 선언된 변수
// 3. 정적변수 (Static Variable)		: 선언된 파일 내부에서만 유효한 전역변수, 초기화는 1번만 수행
// 4. 외부변수 (External Variable)	: 다른 파일에 선언된 전역변수 (어떤 파일이든 상관 없음)

// 메모리 영역
// 1. 스택 영역 (Stack Area)		- 지역변수
// 2. 데이터	영역 (Data Area)		- 전역변수, 정적변수, 외부변수
// 3. 읽기 전용 (코드, ROM) 영역	- 상수 (const)
// 4. 힙 영역 (Heap Area)		- 동적할당변수 (new, malloc)


// 전역변수
int g_i = 0; // Date 영역

// Data 영역 특징
// 프로그램 시작 시 생성
// 프로그램 종료 시 해제

#include "func.h"
#include "common.h"



// 정적변수
//static int g_iStatic = 0; // Data 영역

int Test()
{
	static int i = 0; // 함수가 종료되어도 값이 유지되는 대신 함수 내에서만 유효
	//int a = 0; // 스택 영역

	++g_i;
	++i;

	return i;

}



int main()
{
	//int i = Mul(10, 20);
	//g_i = 100; // 가능
	//i = 50; // 불가능, static i 는 Test 함수 내에서만 유효
	
	g_iStatic = 100;
	g_iExtern = 500;
	// F12 : 선언된 위치로 이동
	Add(0, 0);

	Test();
	Test();
	Test();
	Test();
	int iCall = Test();

	g_i = 0;
	printf("Test 함수 호출 횟수 : %d\n", iCall);



	// 포인터 변수: 주소를 저장하는 변수
	// 자료형 + * 변수명
	// 자료형: 해당 포인터에게 전달된 주소를 해석하는 단위
	//int* pInt = nullptr; // 0 이랑 같음
	int i = 100;
	float f = 3.f;

	//int* pInt = &i; // int 뒤에 별을 붙이면 포인터 변수가 되고 변수 앞에 &를 붙이면 그 i의 주소
	int* pInt = (int*)&f; // &f 만 넣으면 컴파일 오류

	// 주소로 접근
	//(*pInt) = 100; // 포인터 변수에 선언된 pInt 참조하겠다, 주소로 가보겠다 -> i 에 100 대입
	i = *pInt;

	// 주소의 단위, byte(= 8 bits)




	return 0;
}

