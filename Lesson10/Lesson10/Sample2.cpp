#include <iostream>
using namespace std;

//func�Լ��� ����
void func();

int a = 0;

//main�Լ�
int main()
{
	for (int i = 0; i<5; i++)
		func();

	return 0;
}

//func�Լ��� ����
void func()
{
	int b = 0;
	static int c = 0;

	cout << " ���� a�� " << a << ", ���� b�� " << b << ", ���� c�� " << c << "�Դϴ�.\n";
	a++;
	b++;
	c++;
}