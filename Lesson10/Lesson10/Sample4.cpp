#include <iostream>
using namespace std;

int main()
{
	int num;
	int* pT;

	cout << "몇 명의 시험 점수를 입력하시겠습니까?\n";

	cin >> num;

	pT = new int[num];

	cout << " 명 분의 점수를 입력하십시오.\n";

	for (int i = 0; i<num; i++) {
		cin >> pT[i];
	}

	for (int j = 0; j<num; j++) {
		cout << j + 1 << "번째 사람의 점수는 " << pT[j] << " 입니다.\n";
	}

	delete[] pT;

	return 0;
}