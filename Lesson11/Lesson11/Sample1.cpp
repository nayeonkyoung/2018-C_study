#include <iostream>
using namespace std;

//������ week�� ����
enum Week{SUN, MON, TUE, WED, THU, FRI,SAT};

int main() {
	Week w;
	w = SUN;

	switch (w) {
		case SUN: cout << "�Ͽ����Դϴ�." << endl; break;
		case MON: cout << "�������Դϴ�." << endl; break;
		case TUE: cout << "ȭ�����Դϴ�." << endl; break;
		case WED: cout << "�������Դϴ�." << endl; break;
		case THU: cout << "������Դϴ�." << endl; break;
		case FRI: cout << "�ݿ����Դϴ�." << endl; break;
		case SAT: cout << "������Դϴ�." << endl; break;
		default: cout << "���� �������� �� �� �����ϴ�." << endl; break;
	}
	return 0;
}