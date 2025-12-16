# include <stdio.h>

// 함수
// Factorial
int Factorial(int _iNum)
{
	int iValue = 1;

	for (int j = 0; j < _iNum - 1; ++j)
	{
		iValue *= (j + 2);
	}

	//Factorial(3); -> // 함수가 쌓이기만 하고 종료되지 않는다

	return iValue;
}

// 재귀함수: 자기 자신을 호출하는 함수
// 가독성, 구현의	용이성
// 단점: 속도가 느리다, 메모리 사용량 증가

// 재귀함수 팩토리얼
int Factorial_Re(int _iNum)
{
	if (_iNum == 1)
	{
		return 1;
	}
	return _iNum * Factorial_Re(_iNum - 1);


}

// 피보나치 수열
// 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
int Fibonacci(int _iNum)
{
	if (_iNum == 1 || _iNum == 2)
	{
		return 1;
	}

	int iPrev1 = 1;
	int iPrev2 = 1;
	int iValue = 0;

	for (int i = 0; i < _iNum - 2; ++i)
	{
		iValue = iPrev1 + iPrev2;
		iPrev1 = iPrev2;
		iPrev2 = iValue;
	}

	return iValue;
}

// 꼬리재귀로 하면 더 잘 해결
int Fibonacci_Re(int _iNum)
{
	if (_iNum == 1 || _iNum == 2)
	{
		return 1;
	}

	return Fibonacci_Re(_iNum - 1) + Fibonacci_Re(_iNum - 2);
}


int main_2()
{
	int iValue = Factorial(5);
	iValue = Factorial(6);
	iValue = Factorial_Re(10);

	iValue = Fibonacci(7);
	iValue = Fibonacci_Re(7);


	// 배열
	// 메모리가 연속적	
	// 배열에 초과했는데 오류가 안나고 다른 변수에 값이 부여될 가능성도 있음
	int iArray[10] = { }; // 빈칸이면 0으로 채워넣음, 4비트짜리	정수형 10개
	iArray[0] = 10; // 첫번째 칸에 10 대입



	return 0;
}
