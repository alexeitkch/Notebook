#include "changeList.h"
#include "definitions.h"
#include "print.h"
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
	cout << "������� ��������!\n";
	system("pause");
	system("cls"); //�������� ������
}
void delByNumber(Person*& list, int& n, int i) {
	//�������� ������ ��� ����� ������ �� 1 ������
	Person* newList = new Person[n - 1];
	//���������� � ����� ������ ��� �������� �� i-��
	for (int j = 0; j < i; j++) {
		newList[j] = list[j];
	}
	//���������� ��� �������� ����� i-��
	for (int j = i + 1; j < n; j++) {
		newList[j - 1] = list[j];
	}
	//������� ������ ������
	delete[] list;
	//������������� ����� ����� 
	list = newList;
	n--;
}
void delContact(Person*& list, int& n) {
	cout << "�������� ��������\n";
	//� ������������ ������������� �������
	char nameGiven[MAX];
	cout << "������� �������: ";
	cin >> nameGiven;
	//�������� ������� � �������� ��������� � ���� ��������
	char vyb;
	int kol = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(list[i].secondName, nameGiven) == 0) {
			print(&list[i]);
			cout << "�������? Y/N: ";
			cin >> vyb;
			if (vyb == 'y' || vyb == 'Y' || vyb == '�' || vyb == '�') {
				delByNumber(list, n, i);
				i--; //???
				kol++;
			}
		}
	}
	if (kol == 0) {
		cout << "�������� �� �������!\n";
	}
	else {
		cout << "�������� �������!\n";
		system("pause");
		system("cls"); //�������� ������
	}
}