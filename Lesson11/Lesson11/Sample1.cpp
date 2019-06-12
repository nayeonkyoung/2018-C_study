#include <iostream>
using namespace std;

//열거형 week의 선언
enum Week{SUN, MON, TUE, WED, THU, FRI,SAT};

int main() {
	Week w;
	w = SUN;

	switch (w) {
		case SUN: cout << "일요일입니다." << endl; break;
		case MON: cout << "월요일입니다." << endl; break;
		case TUE: cout << "화요일입니다." << endl; break;
		case WED: cout << "수요일입니다." << endl; break;
		case THU: cout << "목요일입니다." << endl; break;
		case FRI: cout << "금요일입니다." << endl; break;
		case SAT: cout << "토요일입니다." << endl; break;
		default: cout << "무슨 요일인지 알 수 없습니다." << endl; break;
	}
	return 0;
}