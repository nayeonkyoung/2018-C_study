#include <iostream>
using namespace std;

//func�Լ��� ����

void func();
int a = 0;

//main�Լ� 
int main()
{
	int b = 1;

	cout << "main�Լ������� a�� b�� ����� �� �ֽ��ϴ�.\n";
	cout << "���� a�� ���� " << a << " �Դϴ�.\n";
	cout << "���� b�� ���� " << b << " �Դϴ�.\n";
	//cout << "���� c�� ���� " << c << " �Դϴ�.\n";

	func();

	return 0;
}

//func�Լ��� ����
void func()
{
	int c = 2;

	cout << "func�Լ������� ���� a�� c�� ����� �� �ֽ��ϴ�.\n";
	cout << "���� a�� ���� " << a << " �Դϴ�.\n";
	//cout << "���� b�� ����" << b << "�Դϴ�.\n";
	cout << "���� c�� ����" << c << "�Դϴ�.\n";
}