#include <iostream>
using namespace std;

//func함수의 선언
void func();

int a = 0;

//main함수
int main()
{
	for (int i = 0; i<5; i++)
		func();

	return 0;
}

//func함수의 정의
void func()
{
	int b = 0;
	static int c = 0;

	cout << " 변수 a는 " << a << ", 변수 b는 " << b << ", 변수 c는 " << c << "입니다.\n";
	a++;
	b++;
	c++;
}