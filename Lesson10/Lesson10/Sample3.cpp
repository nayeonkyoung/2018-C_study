#include <iostream>
using namespace std;

int main()
{
	int* pA;

	pA = new int;

	cout << "�������� �޸𸮸� Ȯ���߽��ϴ�.\n";

	*pA = 10;

	cout << "�������� Ȯ���� �޸𸮸� ����Ͽ� " << *pA << " ��(��) ����߽��ϴ�.\n";

	delete pA;

	cout << "Ȯ���� �޸𸮸� �����߽��ϴ�.\n";

	return 0;
}