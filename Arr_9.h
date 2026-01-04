#pragma once

typedef struct _tabArr
{
	// 가변배열을 위해서는 아래 3가지를 멤버로 가져야 한다.
	int* pInt; // 동적할당을 위해서는 힙영역의 주소를 저장할 포인터 필요
	int iCount; // 현재까지 메모리에 할당된게 얼마나 되는지 알아야 하니까
	int iMaxCount; // 최대 몇개까지 할당할건지도 알아야 하니까
}tArr;

// 단축키: Ctrl + '+' + '.' : 함수 정의부 자동생성

// 배열 초기화 함수
void InitArr(tArr* _pArr); 

// 데이터 추가 함수
void PushBack(tArr* _pArr, int _iData);

// 배열 메모리 해제 함수
void ReleaseArr(tArr* _pArr);

// 데이터 정렬 함수
void Sort(tArr* _pArr, void (*SortFunc)(int*, int))
{
	_pArr;
	SortFunc(_pArr->pInt, _pArr->iCount);
}
