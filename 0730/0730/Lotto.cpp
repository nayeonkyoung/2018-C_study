#include <iostream>
#include <time.h>

using namespace std;

int main() {
	cout << "������ �ζ� ��ȣ��~~?" << endl;
	srand((unsigned int)time(0));
	int lotto[6];
	
	cout << "*****************" << endl;
	for (int i=0; i < 6; i++) {
		lotto[i]=((rand() % 45) + 1);
		cout <<	"\t" << lotto[i]  << endl;
	}
	cout << "*****************" << endl;

	return 0;
}