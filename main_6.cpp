#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

// 메모리 영역
// 1. 스택	: 지역 변수, 매개 변수, 함수 호출 시 생성, 함수 종료 시 소멸
// 2. 데이터	: 전역 변수, static 변수, 프로그램 시작 시 생성, 프로그램 종료 시 소멸
// 3. 힙		: 동적 할당, 프로그래머가 직접 관리, 할당과 해제를 직접 해야 함
// 4. ROM   : 실행 코드, 프로그램 시작 시 생성, 프로그램 종료 시 소멸 (Read Only Memory, 코드)


void Output(const int* pI) // int 변수를 입력 받을건데 변수를 수정하지 않겠다는 의미
{
	int i = *pI;
	//int* pInt = (int*)pI; // const 제거 가능 (위험한 방법)
	//*pInt = 200; // 원본 수정 가능 (위험한 방법)

}


int main()
{
    // 1. const
	const int i = 100;

	// const 와 포인터
	int a = 0;
	int* pInt = &a;

	// 포인터를 통해 수정할 수 있는 것
	*pInt = 1;		// 주소의 값 변경 가능
	pInt = nullptr; // 대상을 가리키는 주소도 변경, 포인터 자체 변경

	// ===========
	// const 포인터
	// ===========
	int b = 0;
	const int* pConstInt = &a; // const int를 가리키는 포인터

	// *pConstInt = 100; // 오류: 가리키는 대상을 수정할 수 없음, 다른 주소로 변경 가능
	pConstInt = &b; // 다른 주소로 변경 가능

	// ===========
	// 포인터 const
	// ===========
	int* const pIntConst = &a; // 포인터 자체는 const, 가리키는 대상은 수정 가능

	*pIntConst = 400; // 가리키는 대상의 값 수정 가능
	//pIntConst = &b; // 오류: 포인터 자체는 변경할 수 없음

	// 초기화 시 가리킨 대상만 가리키고 가리키는 원본을 수정할 수 없음
	const int* const pConstIntConst = nullptr;

	int const* p = &a; // const int를 가리키는 포인터, const int*와 동일, * 앞뒤를 기준으로 생각
	//*p = 0; // 오류: 가리키는 대상의 값을 수정할 수 없음
	
	{
		int a = 0;
		const int* pInt = &a;
		//a = 100; // 원본 수정 가능
		//*pInt = 100; // 오류: 포인터를 통해서는 수정 불가

		int* p = &a;
		*p = 200; // 포인터를 통해 수정 가능, const 가 아닌 다른 포인터로 a를 가리키기에 수정 가능
	}

	
	a = 100;
	Output(&a);


	// void * (포인터)
	// 1. 원본의 자료형을 정하지 않음
	// 2. 모든 자료형의 주소를 저장할 수 있음
	// 3. void 포인터는 역참조 불가
	// 4. 주소 연산 불가 (크기를 알 수 없기 때문)
	void* pVoid = nullptr; // 모든 타입을 가리킬 수 있는 포인터

	{
		int a = 0;
		float f = 0.f;
		double d = 0.;
		long long ll = 0;

		pVoid = &a;	 // int 주소 저장
		pVoid = &f;	 // float 주소 저장
		pVoid = &d;	 // double 주소 저장
		pVoid = &ll; // long long 주소 저장

		//*pVoid = 100; // 오류: void 포인터는 값을 수정할 수 없음 (역참조 불가)
		//pVoid + 1;	// 오류: void 포인터는 산술 연산 불가 (크기를 알 수 없기 때문)
	}

	{
		// 문자
		wchar_t wc = 49; // 유니코드 문자 '1', ASCII 코드 참고
		short s = 49;	 // 그대로 숫자 49

		// 문자열
		// char(1), wchar_t(2), char16_t(2), char32_t(4)
		// wchar_t : 문자 하나를 2 byte로 표현 (유니코드)
		char c = 'a';
		wchar_t wc = L'a';

		char szChar[10] = "abcdef";

		// 문자 하나하나가 2 byte, 마지막에는 null
		// 아래는 {97,98,99,100,101,102,} 와 동일
		wchar_t szWCahr[10] = L"abcdef";  // 스택 메모리에 해당 배열 생성
		// 아래는 문자열의 반환 타입이 애시당초 const 이기 때문에 const 지울 수 없음
		const wchar_t* pChar = L"abcdef"; // 문자열은 아니고, 별도의 메모리 영역(코드 영역, 읽기 전용 메모리 등)에 생성
		//wchar_t* pChar = (wchar_t*)L"abcdef"; // const 제거 억지로 가능 (위험한 방법)

		szWCahr[1] = 'z'; // 수정 가능
		//pChar[1] = 'z'; // *(pChar + 1) = 'z'; // 오류: 수정 불가
		szWCahr[0]; // 스택메모리의 값을 읽음
		pChar[0];   // 코드 영역의 값을 읽음

		short arrShort[10] = { 97, 98, 99, 100, 101, 102, }; // L"abcdef" 와 동일하지만 허용 안 됨


		unsigned char szTest[10] = "abc한글"; // 멀티바이트 문자열 (1 byte + 2 byte)
		wchar_t szTest[10] = L"abc한글"; // 와이드바이트 문자열 (2 byte)
	}

	{
		wchar_t szName[10] = L"Raimond";

		int iLen = wcslen(szName); // 배열의 이름이 시작 주소이기에 포인터로 전달

	}

	return 0;

}

// 단축키 
// Ctrl + Shift + Space : 함수 매개변수 정보

