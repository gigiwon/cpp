#include <iostream>
#include <time.h>


#include "Arr.h"
#include "LikedList.h"


void BubbleSort(int* _pData, int _iCount)
{
	// 데이터가 1개 이하면 정렬하지 않아도 됨
	if (_iCount <= 1)
		return;

	// 오름차순 정렬
	while (true)
	{
		bool bFinish = true; // 한번도 스왑이 일어나지 않으면 정렬 끝

		int iLoop = _iCount - 1;
		for (int i = 0; i < iLoop; ++i)
		{
			if (_pData[i] > _pData[i + 1])
			{
				int iTemp = _pData[i];
				_pData[i] = _pData[i + 1];
				_pData[i + 1] = iTemp;

				bFinish = false; // 스왑이 일어났으므로 정렬 계속
			}
		}

		if (bFinish)
			break;
	}
}


void Test(void)
{

}


int main()
{
	// 반환 type이 void 이고 매개변수가 없는 함수 포인터
	void (*pFunc)(void) = nullptr;
	pFunc = Test;
	pFunc(); // Test() 함수 호출


	int iArr[10] = { 87, 644, 23, 45, 12, 78, 99, 1, 5, 33 };
	BubbleSort(iArr, 10);
	

	tArr s1 = {};

	InitArr(&s1); // 이렇게만 끝나면 메모리 누수 발생

	// 난수 (랜덤)
	srand(time(nullptr)); // 시간을 시드값으로 설정
	
	for (int i = 0; i < 10; ++i)
	{
		int iRand = rand() % 100 + 1; // 1~100 사이의 난수 생성
		PushBack(&s1, iRand);
	}

	printf("정렬 전\n");
	for (int i = 0; i < s1.iCount; ++i)
	{
		printf("%d\n", s1.pInt[i]);
	}

	Sort(&s1, &BubbleSort);

	printf("\n");
	printf("정렬 후\n");
	for (int i = 0; i < s1.iCount; ++i)
	{
		printf("%d\n", s1.pInt[i]);
	}

	ReleaseArr(&s1);

	return 0;
}

// 1. 가변배열
// 스스로 구현 가능하게 복습할 것

// 2. 가변배열 안에 넣은 데이터 정렬
// - 버블정렬 (오름이든 내림이든 상관없음)
