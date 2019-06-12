/*
은행
-구조체-
계좌번호(임의로 10자리)
사람이름
개설날짜(입력)
용도
잔액

-메뉴-
계좌개설
입금(+=)
출금(-+)
계좌확인(입력 -> 계좌 정보 출력)

*/
#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

#define ACCOUNTNUM_SIZE 30
#define NAME_SIZE 10
#define MADEDAY_SIZE 30
#define PURPOSE_SIZE 50
#define ACCOUNT_SIZE 10
#define INPUT_SIZE 30
#define OUTPUT_SIZE 30

struct sBank {
	char strAccount[ACCOUNTNUM_SIZE];
	char strName[NAME_SIZE];
	char strOpen[MADEDAY_SIZE];
	char strPurpose[PURPOSE_SIZE];
	int balance = 0;
};

enum{ MENU_NONE, MENU_OPENING, MENU_DEPOSIT, MENU_WITHDRAWAL, MENU_CONFIRMATION, MENU_END };

int main() {
	srand((unsigned int)time(0));

	sBank sBankArr[ACCOUNT_SIZE];
	int bankCount = 0;
	char strName[NAME_SIZE] = {};
	char strAccount[ACCOUNTNUM_SIZE] = {};
	char strInput[INPUT_SIZE] = {}, strOutput[OUTPUT_SIZE] = {};
	int inputmoney, outputmoney;
	
	while (true) {
		system("cls");
		cout << "============메뉴선택============" << endl;
		cout << "1. 계좌 개설" << endl;
		cout << "2. 입금" << endl;
		cout << "3. 출금" << endl;
		cout << "4. 계좌 확인" << endl;
		cout << "5. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		int menu;
		cin >> menu;

		if (menu == MENU_END)
			break;

		switch (menu) {
		case MENU_OPENING :
			system("cls");
			cout << "!!!!!계좌개설!!!!!" << endl;

			cout << "개설할 통장의 계좌번호 10자리를 입력해주세요 : ";
			cin >> sBankArr[bankCount].strAccount;

			cout << "이름 : ";
			cin >> sBankArr[bankCount].strName;

			cin.ignore(1024, '\n');

			cout << "개설날짜(yyyy-mm-dd로 입력) : ";
			cin.getline(sBankArr[bankCount].strOpen, MADEDAY_SIZE);

			cout << "용도 : ";
			cin.getline(sBankArr[bankCount].strPurpose, PURPOSE_SIZE);
	
			bankCount++;
			cout << "추가 완료!" << endl;
			break;
		case MENU_DEPOSIT:
			system("cls");
			cout << "============입금============" << endl;

			cin.ignore(1024, '\n');

			cout << "입금하실 분의 이름을 입력해 주세요 : ";
			cin.getline(strInput, INPUT_SIZE);

			cout << endl << "입금하실 금액을 입력해 주세요 : ";
			cin >> inputmoney;

				for (int i = 0; i < bankCount; i++) {
					if (strcmp(sBankArr[i].strName, strName) == 0) {
						sBankArr[i].balance += inputmoney;
						cout << sBankArr[i].strName << "님의 계좌에 " << inputmoney << "원이 입금되었습니다." << endl;
						cout << "현재 잔액 : " << sBankArr[i].balance << endl;
					}
				}
			break;
		case MENU_WITHDRAWAL:
			system("cls");
			cout << "============출금============" << endl;

			cin.ignore(1024, '\n');

			cout << "출금하실 분의 이름을 입력해 주세요 : ";
			cin.getline(strOutput, OUTPUT_SIZE);

			cout << endl << "출금하실 금액을 입력해 주세요 : ";
			cin >> outputmoney;

			for (int i = 0; i < bankCount; i++) {
				if (strcmp(sBankArr[i].strName, strName) == 0) {
					sBankArr[i].balance -= outputmoney;
					cout << sBankArr[i].strName << "님의 계좌에서 " << outputmoney << "가 빠져나갔습니다." << endl;
					cout << "현재 잔액 : " << sBankArr[i].balance << endl;
				}
			}
			break;
		case MENU_CONFIRMATION:
			system("cls");
			cout << "============계좌확인============" << endl;
			cin.ignore(1024, '\n');

			cout << "정보를 보실 분의 이름을 입력해 주세요 : ";
			cin.getline(strName, NAME_SIZE);

			for (int i = 0; i < bankCount; i++) {
				if (strcmp(sBankArr[i].strName, strName) == 0) {
					cout << "계좌번호 : " << sBankArr[i].strAccount << endl;
					cout << "이름 : " << sBankArr[i].strName << endl;
					cout << "개설 날짜 : " << sBankArr[i].strOpen << endl;
					cout << "용도 : " << sBankArr[i].strPurpose << endl;
					cout << "잔액 : " << sBankArr[i].balance << endl;
				}
			}
			break;
		defalut:
			cout << "메뉴를 잘못선택하셨습니다!" << endl;
			break;
		}
		system("pause");
	}
}