#include <iostream>
using namespace std;

int main()
{
	int* pA;

	pA = new int;

	cout << "동적으로 메모리를 확보했습니다.\n";

	*pA = 10;

	cout << "동적으로 확보한 메모리를 사용하여 " << *pA << " 을(를) 출력했습니다.\n";

	delete pA;

	cout << "확보한 메모리를 해제했습니다.\n";

	return 0;
}