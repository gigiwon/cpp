#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include <assert.h> // 경고 만들어서 사용자가 문제 인식하게 함


// 메모리 영역
// 1. 스택	: 지역 변수, 매개 변수, 함수 호출 시 생성, 함수 종료 시 소멸
// 2. 데이터	: 전역 변수, static 변수, 프로그램 시작 시 생성, 프로그램 종료 시 소멸
// 3. 힙		: 동적 할당, 프로그래머가 직접 관리, 할당과 해제를 직접 해야 함
// 4. ROM   : 실행 코드, 프로그램 시작 시 생성, 프로그램 종료 시 소멸 (Read Only Memory, 코드)


// 함수 오버로딩: 같은 이름으로 여러 개의 함수를 정의하는 것
// 함수 오버라이딩: 상속 관계에서 부모 클래스의 함수를 자식 클래스에서 재정의하는 것
void Test(int a)
{

}

void Test(int a, int b) // or void Test(float a)
{
	
}


typedef struct _tagMyST
{
	int		a; // 멤버
	float	f;
}MYST;


unsigned int GetLength(const wchar_t* _pStr)
{
	//_pStr[0]; // szName[0] 복사한 배열의 첫 번째 요소 접근, 수정 불가
	
	// 문자 개수 체크
	int i = 0; // while 안에 넣으면 매번 0으로 초기화 됨

	//while ('\0' != _pStr[i]) // 더 쉽지만 아래가 더 직관적
	//{
	//	++i;
	//}

	while (true)
	{
		wchar_t c = _pStr[i];

		if ('\0' == c) // c = '\0' 같은 실수 안하게 비교연산할 때 상수 먼저 쓰는 습관
		{
			break;
		}

		++i;

	}

	return i;
}


// 크기를 넣는 이유는 붙이고자 하는 대상에 크기가 초과될까봐
void StrCat(wchar_t * _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc)
{
	// 예외처리: 이어붙인 최종 문자열의 길이가 목적지 저장 공간을 넘어서는 경우
	int iDestLen = GetLength(_pDest);
	int iSrcLen = GetLength(_pSrc);

	if (_iBufferSize < iDestLen + iSrcLen + 1) // +1은 null 문자 공간
	{
		assert(nullptr); // 강제로 오류 발생
	}

	// 문자열 이어 붙이기
	// 1. Dest 문자열의 끝 확인 (문자열이 이어 붙을 시작 위치)
	iDestLen; // Dest 문자열의 끝 인덱스

	// 2. 반복적으로 Src 문자열을 Dest 끝 위치에 복사
	// 3. Src 문자열의 끝을 만나면 반복 종료
	for (int i = 0; i < iSrcLen + 1; ++i) // +1은 null 문자 복사
	{
		_pDest[iDestLen + i] = _pSrc[i];
	}
	
}


// 문자의 길이 비교 후 다르면 오류 반환
// 문자열의 아스키 코드 값 다 더하기
// 최종 숫자랑 왼쪽 오른쪽 비교
// 왼쪽이 크면 -1, 오른쪽이 크면 1, 같으면 0
int test_giwon(const wchar_t* _left, const wchar_t* _right)
{
	if (GetLength(_left) != GetLength(_right))
	{
		assert(nullptr);
	}
	
	int _left_count = 0;
	int _right_count = 0;

	for (int i = 0; i < GetLength(_left) + 1; ++i)
	{
		_left_count += (int) _left[i];
		_right_count += (int) _right[i];

	}

	int a = -1;
	int b = 0;
	int c = 1;
	int d;

	if (_left_count > _right_count)
	{
		d = a;
	}

	if (_left_count < _right_count)
	{
		d = c;
	}

	if (_left_count == _right_count)
	{
		d = b;
	}

	return d;
}


int StrCmp(const wchar_t* _left, const wchar_t* _right)
{
	int leftLen = GetLength(_left);
	int rightLen = GetLength(_right);

	int iLoop = leftLen;
	int iReturn = 0;

	if (leftLen < rightLen)
	{
		iLoop = leftLen;
		iReturn = -1;
	}
	else if (leftLen > rightLen)
	{
		iLoop = rightLen;
		iReturn = 1;
	}

	for (int i = 0; i < iLoop; ++i)
	{
		if (_left[i] < _right[i])
		{
			return -1;
		}
		else if (_left[i] > _right[i])
		{
			return 1;
		}
	}

	return iReturn;
}


int main()
{
	wchar_t szName[10] = L"Raimond";

	//int iLen = wcslen(szName); // 배열의 이름이 시작 주소이기에 포인터로 전달
	int iLen = GetLength(szName);


	// 문자열 이어 붙이기
	wchar_t szString[10] = L"abc";
	//wcscat_s(szString, 100, L"def");
	//wcscat_s(szString, 100, L"ghi");

	StrCat(szString, 10, L"def");


	// 함수 오버로딩
	Test(10); // int 매개 변수 버전 호출
	Test(10.f); // float 매개 변수 버전 호출


	// 과제
	// 두 문자열이 완벽하게 일치하면 0 반환, 저울 같은 개념
	// 양 우열을 비교해서 L: -1, R: 1 반환 (문자의 아스키 코드 값이 더 큰 쪽이 우위)
	int iRet = wcscmp(L"abc", L"abc");

	test_giwon(L"abcf", L"abd");
	iRet = StrCmp(L"abc", L"abd");


	// 구조체와 포인터
	MYST s = {};

	MYST* pST = &s;
	pST + 1; // 8 bytes 증가 (int 4bytes + float 4bytes)	

	(*pST).a = 10; // 포인터가 가리키는 구조체의 멤버에 접근
	pST->a = 10; // 위와 동일한 표현


	return 0;
}

// 단축키 
// Ctrl + Shift + Space : 함수 매개변수 정보

