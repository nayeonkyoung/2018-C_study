/*
����
-����ü-
���¹�ȣ(���Ƿ� 10�ڸ�)
����̸�
������¥(�Է�)
�뵵
�ܾ�

-�޴�-
���°���
�Ա�(+=)
���(-+)
����Ȯ��(�Է� -> ���� ���� ���)

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
		cout << "============�޴�����============" << endl;
		cout << "1. ���� ����" << endl;
		cout << "2. �Ա�" << endl;
		cout << "3. ���" << endl;
		cout << "4. ���� Ȯ��" << endl;
		cout << "5. ����" << endl;
		cout << "�޴��� �����ϼ��� : ";
		int menu;
		cin >> menu;

		if (menu == MENU_END)
			break;

		switch (menu) {
		case MENU_OPENING :
			system("cls");
			cout << "!!!!!���°���!!!!!" << endl;

			cout << "������ ������ ���¹�ȣ 10�ڸ��� �Է����ּ��� : ";
			cin >> sBankArr[bankCount].strAccount;

			cout << "�̸� : ";
			cin >> sBankArr[bankCount].strName;

			cin.ignore(1024, '\n');

			cout << "������¥(yyyy-mm-dd�� �Է�) : ";
			cin.getline(sBankArr[bankCount].strOpen, MADEDAY_SIZE);

			cout << "�뵵 : ";
			cin.getline(sBankArr[bankCount].strPurpose, PURPOSE_SIZE);
	
			bankCount++;
			cout << "�߰� �Ϸ�!" << endl;
			break;
		case MENU_DEPOSIT:
			system("cls");
			cout << "============�Ա�============" << endl;

			cin.ignore(1024, '\n');

			cout << "�Ա��Ͻ� ���� �̸��� �Է��� �ּ��� : ";
			cin.getline(strInput, INPUT_SIZE);

			cout << endl << "�Ա��Ͻ� �ݾ��� �Է��� �ּ��� : ";
			cin >> inputmoney;

				for (int i = 0; i < bankCount; i++) {
					if (strcmp(sBankArr[i].strName, strName) == 0) {
						sBankArr[i].balance += inputmoney;
						cout << sBankArr[i].strName << "���� ���¿� " << inputmoney << "���� �ԱݵǾ����ϴ�." << endl;
						cout << "���� �ܾ� : " << sBankArr[i].balance << endl;
					}
				}
			break;
		case MENU_WITHDRAWAL:
			system("cls");
			cout << "============���============" << endl;

			cin.ignore(1024, '\n');

			cout << "����Ͻ� ���� �̸��� �Է��� �ּ��� : ";
			cin.getline(strOutput, OUTPUT_SIZE);

			cout << endl << "����Ͻ� �ݾ��� �Է��� �ּ��� : ";
			cin >> outputmoney;

			for (int i = 0; i < bankCount; i++) {
				if (strcmp(sBankArr[i].strName, strName) == 0) {
					sBankArr[i].balance -= outputmoney;
					cout << sBankArr[i].strName << "���� ���¿��� " << outputmoney << "�� �����������ϴ�." << endl;
					cout << "���� �ܾ� : " << sBankArr[i].balance << endl;
				}
			}
			break;
		case MENU_CONFIRMATION:
			system("cls");
			cout << "============����Ȯ��============" << endl;
			cin.ignore(1024, '\n');

			cout << "������ ���� ���� �̸��� �Է��� �ּ��� : ";
			cin.getline(strName, NAME_SIZE);

			for (int i = 0; i < bankCount; i++) {
				if (strcmp(sBankArr[i].strName, strName) == 0) {
					cout << "���¹�ȣ : " << sBankArr[i].strAccount << endl;
					cout << "�̸� : " << sBankArr[i].strName << endl;
					cout << "���� ��¥ : " << sBankArr[i].strOpen << endl;
					cout << "�뵵 : " << sBankArr[i].strPurpose << endl;
					cout << "�ܾ� : " << sBankArr[i].balance << endl;
				}
			}
			break;
		defalut:
			cout << "�޴��� �߸������ϼ̽��ϴ�!" << endl;
			break;
		}
		system("pause");
	}
}