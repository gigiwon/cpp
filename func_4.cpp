#include "func.h"
#include "common.h"

#include <stdio.h>

//int g_i = 0; // main.cpp에서 선언되었기 때문에 링크 에러 발생
//static int g_iStatic = 0; // static이 붙어있기 때문에 링크 에러 발생 안함


int Add (int a, int b)
{
	printf("g_iStatic : %d \n", g_iStatic);
	printf("g_iExtern: %d \n", g_iExtern);
	return a + b;
}

int Sub (int a, int b)
{
	return a - b;
}

int Mul (int a, int b)
{
	return a * b;
}	
