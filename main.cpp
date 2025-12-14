#include <stdio.h>


// # 은 전처리 기능인데, 이건 무조건 먼저 실행
// #define 은 치환 -> 매크로 정의
// #define 장점
// 1. 가독성
// 2. 유지보수성 향상 (전체 수정할 필요 없음)

#define HUNGRY   0x001 // 첫번째 상태, 16진수 표기법
#define THIRSTY  0x002 // 두번째 상태
#define TIRED    0x004 // 세번째 상태
#define FIRE     0x008 // 네번째 상태

#define COLD     0x010 // 다섯번째 상태
#define POISON1  0x020 // 여섯번째 상태
#define POISON2  0x040 
#define POISON3  0x080 

#define POISON4  0x100 
#define POISON5  0x200 


// 주석
// 설명, 코드로 인식되지 않는다


// 전역변수
int global = 0;

int Add(int left, int right) // left, right 는 지역변수
{
	return left + right;
}


// 함수
int main()
{
	// 자료형: 정수형, 실수형 (크기 단위, byte) 
	// 정수형: char(1), short(2), int(4), long(4), long long(8)
	// 실수형: float(4), double(8)
	int i = 0;

	// 256 -> 0 ~ 255
	unsigned char c = 0;
	c = 0;
	// c = 255;
	c = -1;

	// 1바이트로 양수,음수 둘 다 표현
	// -128 ~ 0 ~ 127
	char c1 = 0;
	c1 = 0;

	// 음의 정수 찾기 (2의 보수)
	// 대응되는 양수의 부호를 반전 후, 1을 더함>>>

	int a = 4 + 4.0;

	// 정수표현과 실수표현 방식은 다르다
	// 실수 표현 방식은 정밀도에 의존
	// 따라서 double자료 형이 float보다 더 아래의 소수점까지 정확하게 표현 가능

	// 정수는 정수, 실수는 실수끼리 연산하되, 두 표현방식의 피 연산자가 연산될 경우 명시적으로 변환하자
	// 아래 float(20)을 20이라고 해도 계산은 되지만 정확하게 float()을 작성해주자
	float f = 10.2415f + (float)20;

	// 실수를 상수로 적을 경우 소수점 뒤에 f를 붙이면 float 자료형으로, f를 붙이지 않으면 double 자료형으로 인식


	// 연산자
	// 대입 연산자, =
	
	// 산술 연산자
	// +,-, *, /, %(모듈러스, 나머지 연산자)
	// ++,-- (증감 연산자)
	// 1의 증감이 아닌 다음 단계의 증감으로 보는 게 더 적절

	int data = 10 + 10; // 대입 연산자보다 산술 연사자가 우선

	// 복합 대입 연산자
	// data = data + 20;
	data += 20;
	
	data = 10 / 3; // 3.33333 -> 3
	data = 10 % 3; // 1

	// data = 10.0 % 3.0; (실수는 %연산자 사용 불가)
	
	data = 10. / 3.; // 3.33333
	data = (int)(10.0 / 3.0); // 3

	data = 0;
	++data; // 전위(전치
	data++; // 후위(후치), 연산자 우선순위가 가장 나중으로 처리됨
	
	data = 0;

	a = 10;
	data = a++; // data = 10, a = 11;
	data = ++a; // data = 11, a = 11;

	data++; // data = data + 1;
	data--; // data = data - 1;
	// data++, ++data 의 경우 특별한 사유가 없으면 전위로 쓰자

	// 논리 연산자
	// ! (invert), && (and), || (or)
	// 참(true), 거짓(false)
	// 0이 아닌 수는 참, 참일 경우 1을 반환
	// 거짓은 0, 거짓일 경우 0을 반환
	int trueflase = true; // 1
	bool trueflase2 = false; // 0

	bool Istrue = 100; // 1로 평가, true/false만 나타내기 때문
	
	Istrue = true;
	Istrue = !Istrue; // false

	int iTrue = 100;
	iTrue = !iTrue; // 0
	int iTruea = 0;
	iTrue = !iTrue; // 1

	iTrue = 0 && 200; // 0
	iTrue = 0 || 200; // 1

	// 비교 연산자
	// ==, !=, >, <, >=, <=
	// 참, 거짓


	// if, else 구문

	data = 0;
	if (0 && 200)
	{
		data = 100;
	}

	if (data == 100) // 위에서 data = 0이므로 false
	{
		data = 200;
	}
	else if (data == 250)// else if 문은 여러 개 사용 가능, if 가 안 될 경우 실행
	{
		data = 300;
	}
	else // if가 false일 때 실행, 없어도 무방
	{
		data = 400;
	}

	// switch case
	switch (10)
	{
		case 10:

			break;
		case 20:

			break;
		default:

			break;
	}

	int iTest = 10;
	if (iTest == 10)
	{

	}
	else if (iTest == 20)
	{

	}
	else
	{

	}
	
	// 아래 2개는 동일
	iTest = 20;

	switch (iTest)
	{
		case 10:
		case 20:
		case 30:

			break;
		default:
			break;
	}

	if (iTest == 10 || iTest == 20 || iTest == 30)
	{

	}


	// 삼항 연산자
	// 가독성이 떨어져서 굳이 사용하지는 않음
	// :?
	// 아래 2개는 동일
	iTest == 20 ? iTest = 100 : iTest = 200;

	if (iTest == 20)
	{
		iTest = 100;
	}
	else
	{
		iTest = 200;
	}


	// 비트 연산자
	// 쉬프트 <<, >>
	unsigned char byte = 1; // 0000 0001
	//byte << 1; // 0000 0010
	byte = byte << 1; // byte <<= 1;
	byte <<= 2; // 0000 1000, 4배 증가, 2^n
	byte >>= 1; // 0000 0100, 2배 감소, 2^-n 의 몫, 감소에는 나머지 개념이 없음
	
	// 비트 곱(&), 합(|), xor(^) 반전(~)
	// 비트단위로 연산 진행
	// & 둘 다 1인 경우, 1
	// | 둘 중 하나라도 1인 경우, 1
	// ^ 같으면 0, 다르면 1
	// ~ 1은 0으로, 0은 1로

	unsigned int iStatus = 0; // iStatus는 32bit(4byte), 32개의 상태를 표현
	
	// 상태 추가
	iStatus |= HUNGRY; // 다른 자리는 그대로 이어지고, HUNGRY 자리는 합치는 값이 무엇이든 1이 유지
	iStatus |= THIRSTY; // iStatus = iStatus | THIRSTY; 마찬가지로 THIRSTY 자리만 1이 유지

	// 상태 확인
	if(iStatus & THIRSTY) // iStatus의 THIRSTY 자리만 검사, 1이면 참, 0이면 거짓
	{
		// 배고픈 상태일 경우, 실행
	}

	// 특정자리 비트 제거
	iStatus &= ~THIRSTY; // THIRSTY 자리만 0으로 변경, 나머지 자리는 그대로


	// 변수
	// 1. 지역변수 (local variable), 함수 내에서 선언된 변수
	// 2. 전역변수 (global variable), 함수 외부에서 선언된 변수
	// 3. 정적변수 (static variable), 함수 내에서 선언되지만, 함수가 종료되어도 메모리에서 사라지지 않는 변수
	// 4. 외부변수 (extern variable), 다른 파일에 선언된 전역변수

	// 지역변수
	int iName = 0;

	// 괄호 안에 선언된 변수(함수, 지역)
	{
		// 변수명 규칙
		int iName = 100;
		{
			{

			}
		}
		iName; // 함수 안 iName 호출

	}

	iName; // 함수 밖 iName 호출


	// 함수 (function), 기능
	// 기능의 모듈화: 작은 함수들이 더 큰 함수, 더 큰 함수들이 모여서 더 큰 함수를 쌓아올리는 것
	data = 10 + 20;
	data = Add(10, 20);

	a = 100;

	int iData = Add(100, 200);


	// 반복문, 조건을 주고 조건이 끝날 때까지 반복
	//for (/*반복자 초기화*/; /*반복자 조건 체크, true/false가 나와야 됨*/; /*반복자 변경*/)
	//{
	//	// 무한루프
	//}

	int x = 0;
	for (int x = 0; x < 10; ++x) // i는 for문 안에서만 유효
	{

		if (x % 2 == 1) // i가 홀수일 경우
		{
			continue; // 아래 코드를 실행하지 않고, 반복문의 조건 체크로 이동
		}

		printf("Output test\n");

		//continue: 아래 코드를 실행하지 않고, 반복문의 조건 체크로 이동
		//break: 반복문 탈출

	}

	int t = 0;
	while (t < 2) /*조건체크*/
	{
		printf("Output test\n");

		++t; // 반복자 변경

		//continue;
		//break;

	}


	// 콘솔 입출력 (명령 프롬프트, 터미널)
	// printf 는 출력 함수
	printf("abcdef %d \n", 10); // %d: 정수형 치환 후 출력
	printf("abcdef %f \n", 10.1234f); // %f: 실수형 치환 후 출력

	for (int i = 0; i < 5; ++i)
	{
		printf("Output i : %d \n", i);
	}

	// scanf 는 입력 함수 
	int iInput = 0;
	scanf_s("%d", &iInput); // %d: 정수형 입력, 콘솔창에 100을 입력하면 iInput에 100이 저장됨


	// 함수
	// 프로그램의 종료는 main 함수의 종료
	// 스택 메모리 영역: 함수가 사용하는 메모리 영역




	return 0;

}

// 단축키
// Ctrl + k + c : 주석처리
// Ctrl + k + u : 주석해제
// Alt Drag : 원하는 영역만 선택

// 디버깅 단축키
// F5 : 디버깅 시작 (디버깅: 버그를 찾아내고 수정하는 과정), 다음 중단점까지 실행
// F9 : 중단점 토글 (토글: 생성 및 해제)
// F10 : 디버깅 중, 구문 한 줄씩 실행 (Step Over)
// F11 : 디버깅 중, 함수 안으로 진입 (Step Into), 더 세부적으로 실행
// Shift + F5 : 디버깅 종료