/*
1. 5*5 빙고판 출력 (1차원 배열을 이용하여 1~25까지의 숫자를 출력)
2. 0을 입력받으면 종료
3. 숫자를 입력받는다.
4. 입력받은 숫자를 *로 바꿔준다.
5. *이 가로 세로 대각선으로 5개면 빙고 카운트 1 증가
6. 빙고라인이 5개가 되면 종료
*/

#include <iostream>
#include <time.h>

#define BingoLine 9


using namespace std;

enum mode {NONE, SINGLE, DUAL, END};
int main()
{
	int MenuInput;
	srand((unsigned int)time(0));
	int Number[(BingoLine * BingoLine)] = {};
	int Number2[(BingoLine * BingoLine)] = {};
	
	while (true) {
		system("cls");
		cout << "1. Single Mode" << endl;
		cout << "2. Dual Mode" << endl;
		cout << "3. End" << endl;
		cout << "게임 모드를 선택하세요 : ";
		cin >> MenuInput;

		if (MenuInput == 3)
			break;
	
	for (int i = 0; i < (BingoLine * BingoLine); i++) {
		Number[i] = i + 1;
		Number2[i] = i + 1;
	}

	int temp, temp1, idx1, idx2;
	for (int i = 0; i < 200; i++) {
		idx1 = rand() % (BingoLine * BingoLine);
		idx2 = rand() % (BingoLine * BingoLine);

		temp = Number[idx1];
		Number[idx1] = Number[idx2];
		Number[idx2] = temp;
	}
	for (int i = 0; i < 200; i++) {
		idx1 = rand() % (BingoLine * BingoLine);
		idx2 = rand() % (BingoLine * BingoLine);

		temp1 = Number2[idx1];
		Number2[idx1] = Number2[idx2];
		Number2[idx2] = temp1;
	}
	int Bingo = 0, Bingo2 = 0;
	switch (MenuInput) {
	case SINGLE :
		while (true) {
			system("cls"); //실행할 때마다 초기화

			cout << "=======================user1=======================" << endl;
			//숫자를 출력
			for (int i = 0; i < BingoLine; i++) {
				for (int j = 0; j < BingoLine; j++) {
					if (Number[i * BingoLine + j] == INT_MAX) {
						cout << "$\t";
					}
					else
						cout << Number[i * BingoLine + j] << "\t";
				}
				cout << endl << endl;
			}

			//숫자를 입력
			cout << "User1 Bingo Line : " << Bingo << endl;

			if (Bingo == BingoLine) {
				cout << "게임을 종료합니다.";
				break;
			}

			cout << "숫자를 입력하시오 : ";
			int input;
			cin >> input;

			if (input == 0) {
				break;
			}
			else if (input < 1 || input >(BingoLine * BingoLine)) {
				continue;
			}
			//입력받은 숫자가 존재하면 INT_MAX값으로 변경
			for (int i = 0; i < (BingoLine * BingoLine); i++) {
				if (input == Number[i]) {
					Number[i] = INT_MAX;
				}
			}

			Bingo = 0;
			int star1 = 0, star2 = 0;
			for (int i = 0; i < BingoLine; i++) {
				star1 = star2 = 0;
				for (int j = 0; j < BingoLine; j++) {
					if (Number[i * BingoLine + j] == INT_MAX)
						star1++;
					if (Number[j * BingoLine + i] == INT_MAX)
						star2++;
				}
				if (star1 == BingoLine)
					Bingo++;
				if (star2 == BingoLine)
					Bingo++;
			}

			star1 = star2 = 0;
			for (int i = 0; i < (BingoLine * BingoLine); i += (BingoLine + 1)) {
				if (Number[i] == INT_MAX)
					star1++;
			}
			if (star1 == BingoLine)
				Bingo++;

			for (int i = (BingoLine - 1); i <= ((BingoLine - 1)*BingoLine); i += (BingoLine - 1)) {
				if (Number[i] == INT_MAX)
					star2++;
			}
			if (star2 == BingoLine)
				Bingo++;
		}
		break;
	case DUAL :
		while (true) {
			system("cls"); //실행할 때마다 초기화

			cout << "=======================user1=======================" << endl;
			//숫자를 5*5로 출력
			for (int i = 0; i < BingoLine; i++) {
				for (int j = 0; j < BingoLine; j++) {
					if (Number[i * BingoLine + j] == INT_MAX) {
						cout << "*\t";
					}
					else
						cout << Number[i * BingoLine + j] << "\t";
				}
				cout << endl;
			}

			cout << "=======================user2=======================" << endl;
			for (int i = 0; i < BingoLine; i++) {
				for (int j = 0; j < BingoLine; j++) {
					if (Number2[i * BingoLine + j] == INT_MAX) {
						cout << "*\t";
					}
					else
						cout << Number2[i * BingoLine + j] << "\t";
				}
				cout << endl;
			}
			//숫자를 입력
			cout << "User1 Bingo Line : " << Bingo << endl;
			cout << "User2 Bingo Line : " << Bingo2 << endl;

			if (Bingo == BingoLine) {
				cout << "User1 승! 게임을 종료합니다.";
				break;
			}
			if (Bingo2 == BingoLine) {
				cout << "User2 승! 게임을 종료합니다.";
				break;
			}

			cout << "숫자를 입력하시오 : ";
			int input;
			cin >> input;

			if (input == 0) {
				break;
			}
			else if (input < 1 || input >(BingoLine * BingoLine)) {
				continue;
			}
			//입력받은 숫자가 존재하면 INT_MAX값으로 변경
			for (int i = 0; i < (BingoLine * BingoLine); i++) {
				if (input == Number[i]) {
					Number[i] = INT_MAX;
				}
			}

			for (int i = 0; i < (BingoLine * BingoLine); i++) {
				if (input == Number2[i]) {
					Number2[i] = INT_MAX;
				}
			}

			Bingo = 0, Bingo2 = 0;
			int star1 = 0, star2 = 0, star3 = 0, star4 = 0;
			for (int i = 0; i < BingoLine; i++) {
				star1 = star2 = star3 = star4 = 0;
				for (int j = 0; j < BingoLine; j++) {
					if (Number[i * BingoLine + j] == INT_MAX)
						star1++;
					if (Number[j * BingoLine + i] == INT_MAX)
						star2++;
					if (Number2[i * BingoLine + j] == INT_MAX)
						star3++;
					if (Number2[j * BingoLine + i] == INT_MAX)
						star4++;
				}
				if (star1 == BingoLine)
					Bingo++;
				if (star2 == BingoLine)
					Bingo++;
				if (star3 == BingoLine)
					Bingo2++;
				if (star4 == BingoLine)
					Bingo2++;
			}

			star1 = star2 = star3 = star4 = 0;
			for (int i = 0; i < (BingoLine * BingoLine); i += (BingoLine + 1)) {
				if (Number[i] == INT_MAX)
					star1++;
				if (Number2[i] == INT_MAX)
					star3++;
			}
			if (star1 == BingoLine)
				Bingo++;
			if (star3 == BingoLine)
				Bingo2++;

			for (int i = (BingoLine - 1); i <= ((BingoLine - 1)*BingoLine); i += (BingoLine - 1)) {
				if (Number[i] == INT_MAX)
					star2++;
				if (Number2[i] == INT_MAX)
					star4++;
			}
			if (star2 == BingoLine)
				Bingo++;
			if (star4 == BingoLine)
				Bingo2++;
		}
		break;
	default:
		break;
	}
	
	}
	return 0;
}