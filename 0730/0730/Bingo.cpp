/*
1. 5*5 ������ ��� (1���� �迭�� �̿��Ͽ� 1~25������ ���ڸ� ���)
2. 0�� �Է¹����� ����
3. ���ڸ� �Է¹޴´�.
4. �Է¹��� ���ڸ� *�� �ٲ��ش�.
5. *�� ���� ���� �밢������ 5���� ���� ī��Ʈ 1 ����
6. ��������� 5���� �Ǹ� ����
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
		cout << "���� ��带 �����ϼ��� : ";
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
			system("cls"); //������ ������ �ʱ�ȭ

			cout << "=======================user1=======================" << endl;
			//���ڸ� ���
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

			//���ڸ� �Է�
			cout << "User1 Bingo Line : " << Bingo << endl;

			if (Bingo == BingoLine) {
				cout << "������ �����մϴ�.";
				break;
			}

			cout << "���ڸ� �Է��Ͻÿ� : ";
			int input;
			cin >> input;

			if (input == 0) {
				break;
			}
			else if (input < 1 || input >(BingoLine * BingoLine)) {
				continue;
			}
			//�Է¹��� ���ڰ� �����ϸ� INT_MAX������ ����
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
			system("cls"); //������ ������ �ʱ�ȭ

			cout << "=======================user1=======================" << endl;
			//���ڸ� 5*5�� ���
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
			//���ڸ� �Է�
			cout << "User1 Bingo Line : " << Bingo << endl;
			cout << "User2 Bingo Line : " << Bingo2 << endl;

			if (Bingo == BingoLine) {
				cout << "User1 ��! ������ �����մϴ�.";
				break;
			}
			if (Bingo2 == BingoLine) {
				cout << "User2 ��! ������ �����մϴ�.";
				break;
			}

			cout << "���ڸ� �Է��Ͻÿ� : ";
			int input;
			cin >> input;

			if (input == 0) {
				break;
			}
			else if (input < 1 || input >(BingoLine * BingoLine)) {
				continue;
			}
			//�Է¹��� ���ڰ� �����ϸ� INT_MAX������ ����
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