#include <iostream>
#include "myfunc.h"
using namespace std;

int main()
{
	int num1, num2, ans;

	cout << "ù ��° ������ �Է��Ͻʽÿ�.\n";
	cin >> num1;

	cout << "�� ��° ������ �Է��Ͻʽÿ�.\n";
	cin >> num2;

	ans = max(num1, num2);

	cout << "�ִ밪��" << ans << "�Դϴ�.\n";

	return 0;
}