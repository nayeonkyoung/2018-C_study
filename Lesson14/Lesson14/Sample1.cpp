#include <iostream>
using namespace std;

class Car {
private:
	int num;
	double gas;
public:
	Car();
	void setCar(int n, double g);
	void show();
};

class RacingCar : public Car {
private:
	int course;
public :
	RacingCar();
	void setCourse(int c);
};

Car::Car() {
	num = 0;
	gas = 0.0;
	cout << "�ڵ����� ����������ϴ�." << endl;
}

void Car::setCar(int n, double g) {
	num = n;
	gas = g;
	cout << "���� ��ȣ��" << num << "����, ���ᷮ��" << gas << "���� �ٲپ����ϴ�." << endl;
}

void Car :: show() {
	cout << "���� ��ȣ��" << num << "�Դϴ�." << endl;
	cout << "���ᷮ��" << gas << "�Դϴ�." << endl;
}

RacingCar::RacingCar() {
	course = 0;
	cout << "���̽� ī ����������ϴ�." << endl;
}

void RacingCar::setCourse(int c) {
	course = c;
	cout << "�ڽ� ��ȣ��" << course << "�� ���߽��ϴ�." << endl;
}

int main() {
	RacingCar rccar1;
	rccar1.setCar(1234, 20.5);
	rccar1.setCourse(5);

	return 0;
}