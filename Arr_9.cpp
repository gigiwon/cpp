#include "Arr.h"

#include <iostream>

void InitArr(tArr* _pArr)
{
	_pArr->pInt = (int*)malloc(sizeof(int) *2 ); // int 사이즈 2개분 명시 (8 byte)
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
}

// 공간 추가 확장
void ReAllocArr(tArr* _pArr)
{
	// 1. 2배 더 큰 공간을 동적할당
	// 새로 할당한 힙 영역의 주소를 저장할 포인터, 스택 영역에 생성
	int* pNew = (int*)malloc(_pArr->iMaxCount * 2 * sizeof(int));

	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사
	for (int i = 0; i < _pArr->iCount; ++i)
	{
		pNew[i] = _pArr->pInt[i];
	}

	// 3. 기존 공간은 메모리 해제
	free(_pArr->pInt);

	// 4. 배열이 새로 할당된 공간을 가리키도록 변경
	_pArr->pInt = pNew;

	// 5. MaxCount 변경점 적용
	_pArr->iMaxCount *= 2;
}

void PushBack(tArr* _pArr, int _iData)
{
	// 힙 영역에 할당한 공간이 꽉 찼는지 확인
	if (_pArr->iCount >= _pArr->iMaxCount)
	{
		// 재할당
		ReAllocArr(_pArr);
	}

	// 데이터 추가
	// 후위증가연산자: 현재 iCount 위치에 데이터 넣고 나서 iCount 1 증가 
	_pArr->pInt[_pArr->iCount++] = _iData; 
}

void ReleaseArr(tArr* _pArr)
{
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}

void Sort(tArr* _pArr)
{
}
