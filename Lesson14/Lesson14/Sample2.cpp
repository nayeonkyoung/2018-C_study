#include <iostream>
using namespace std;

class Car {
private:
	int num;
	double gas;
public:
	Car();
	Car(int n, double g);
	void setCar(int n, double g);
	void show();
};

class RacingCar : public Car {
private:
	int course;
public:
	RacingCar();
	RacingCar(int n, double g, int c);
	void setCourse(int c);
};

Car::Car() {
	num = 0;
	gas = g;
	cout << "���� ��ȣ��" << num << "�̰�, ���ᷮ��" << gas << "�� �ڵ����� ����������ϴ�." << endl;
}

void Car::show() {
	cout << "���� ��ȣ��" << num << "�Դϴ�." << endl;
	cout << "���ᷮ��" << gas << "�Դϴ�." << endl;
}

RacingCar::RacingCar() {
	course = 0;
	cout << "���̽� ī ����������ϴ�." << endl;
}

RacingCar :: RacingCar::RacingCar(int n, double g, int c) : Car(n, g) {
	course = c;
	cout << "�ڽ� ��ȣ��" << course << "�� ���̽� ī�� ����� �����ϴ�." << endl;
}

void RacingCar::setCourse(int c) {
	course = c;
	cout << "�ڽ� ��ȣ��" << course << "�� ���߽��ϴ�." << endl;
}

int main() {
	RacingCar rccar1(1234, 20.5, 5);

	return 0;
}
