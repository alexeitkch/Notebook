#include "changeList.h"
#include "definitions.h"
#include <iostream>
using namespace std;

void addContact(Person*& list, int& n) {
	//��������� ����� ������ ��� ������ ������� n+1
	Person* newList = new Person[n + 1];
	//����������� ���� ������ �� ��������� ������� � �����
	for (int i = 0; i < n; i++) {
		newList[i] = list[i];
	}
	//����������� � ������������ ������ ����� ��������, ��������� � ����� �������
	cout << "������� �������: ";
	cin >> newList[n].secondName;
	cout << "������� ���: ";
	cin >> newList[n].name;
	cout << "������� �������: ";
	cin >> newList[n].telefon;
	cout << "������� ����, ����� � ��� �������� ����� ������: ";
	cin >> newList[n].birthday.day;
	cin >> newList[n].birthday.month;
	cin >> newList[n].birthday.year;
	//�������� ������ �� ������ �������
	delete[] list;
	//����� ������ ��������������� � list
	list = newList;
	n++;
}
void delContact(Person*& list, int& n) {
	cout << "�������� ��������\n";
}