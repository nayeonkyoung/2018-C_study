#include <iostream>
using namespace std;

int main()
{
	int num;
	int* pT;

	cout << "�� ���� ���� ������ �Է��Ͻðڽ��ϱ�?\n";

	cin >> num;

	pT = new int[num];

	cout << " �� ���� ������ �Է��Ͻʽÿ�.\n";

	for (int i = 0; i<num; i++) {
		cin >> pT[i];
	}

	for (int j = 0; j<num; j++) {
		cout << j + 1 << "��° ����� ������ " << pT[j] << " �Դϴ�.\n";
	}

	delete[] pT;

	return 0;
}