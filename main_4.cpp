#include <stdio.h>

// 변수종류
// 1. 지역변수 (Local Variable): 함수 내부에 선언된 변수
// 2. 전역변수 (Global Variable): 함수 외부에 선언된 변수
// 3. 정적변수 (Static Variable): 함수 내부에 선언되지만 static 키워드가 붙은 변수
// 4. 외부변수 (External Variable): 다른 파일에 선언된 전역변수

// 메모리 영역
// 1. 스택 영역 (Stack Area) - 지역변수
// 2. 데이터	영역 (Data Area) - 전역변수, 정적변수, 외부변수
// 3. 읽기 전용 (코드, ROM) 영역 - 상수 (const)
// 4. 힙 영역 (Heap Area) - 동적할당변수 (new, malloc)


// 전역변수
int g_i = 0; // Date 영역

// Data 영역 특징
// 프로그램 시작 시 생성
// 프로그램 종료 시 해제

#include "func.h"

void Test(); // 미리 함수 선언하고 나중에 컴파일 단계에서 호출

int main()
{
	// 지역변수
	int a = 0;
	Test();
	Test();
	Test();


	return 0;
}

void Test() // void: 반환 해주는게 없는 함수
{
	// 전역변수는 되지만 지역변수는 안됨
	++g_i;

}
