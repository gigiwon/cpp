#include <stdio.h>



// 구조체: 사용자 정의 자료형 (User Defined Data Type)
typedef struct _tagMyST
{
	int		a; // int 파트의 이름 (변수의 선언이 아님)
	float	f;
} MYST;

// 구조체도 모듈화 가능
// c++에서는 typedef 생략 가능 (c언어 호환성 위해 사용)
typedef struct _tagBig
{
	MYST	k; 
	int		c;
	char	d;
} BIG;

typedef int INT; // 기본 자료형도	별칭 가능



int main()
{	
	int arr[10] = { 1,2,3,4,5,6 }; // 배열 초기화, 미입력은 0으로 초기화


	// 구조체
	MYST t = { 100, 3.14f }; // 구조체도 초기화 가능
	t.a = 10;
	t.f = 10.2312f;

	int iSize = sizeof(MYST);



	return 0;
}
