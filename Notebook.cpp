#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include "definitions.h"
#include "print.h"
#include "changeList.h"
#include "find.h"

void razbor(char* str, Person &kontakt) {
	char* part, * buf = NULL;
	part = strtok_s(str, ";", &buf);
	strncpy_s(kontakt.secondName, part, sizeof(kontakt.secondName) - 1);
	part = strtok_s(NULL, ";", &buf);
	strncpy_s(kontakt.name, part, sizeof(kontakt.name) - 1);
	part = strtok_s(NULL, ";", &buf);
	strncpy_s(kontakt.telefon, part, sizeof(kontakt.telefon) - 1);
	part = strtok_s(NULL, "/", &buf);
	kontakt.birthday.day = atoi(part);
	part = strtok_s(NULL, "/", &buf);
	kontakt.birthday.month = atoi(part);
	part = strtok_s(NULL, "\n", &buf);
	kontakt.birthday.year = atoi(part);
}

//������� ����
int menu() {
	cout << "\n1 - �������� ������\n";
	cout << "2 - ������� ������\n";
	cout << "3 - ������� ��� ����������\n";
	cout << "4 - ������� ������, ��������������� �� �������\n";
	cout << "5 - ����� �� �������\n";
	cout << "6 - ������ ����������� � ������������ ������\n";
	cout << "7 - ����� �� ���������\n";
	int k;
	cout << "��� �����: ";
	cin >> k;
	while (k < 1 || k > 7) {
		cout << "�������� �����! �������� ����: ";
		cin >> k;
	}
	cout << endl;
	return k;
}

//������� ���������� ������
void finish(Person* list, int n) {
	cout << "���������� ������\n";
	cout << "��������� � ���� ������� ��������? (Y/N) ";
	char vyb;
	cin >> vyb;
	if (vyb == 'y' || vyb == 'Y' || vyb == '�' || vyb == '�') {
		//�������� ����� data.txt
		FILE* output = NULL;
		if (fopen_s(&output, "data.txt", "w") != 0) {
			cout << "������ �������� ����� ��� ������\n";
			return;
		}
		fprintf(output, "%d\n", n);
		for (int i = 0; i < n; i++) {
			fprintf(output, "%s;%s;%s;%d/%d/%d\n", list[i].secondName, list[i].name, list[i].telefon, list[i].birthday.day, list[i].birthday.month, list[i].birthday.year);
		}
		//�������� �����
		if (fclose(output) != 0) {
			cout << "������ �������� ����� ��� ������\n";
		}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	//�������� ����� data.txt
	FILE* input = NULL;
	if (fopen_s(&input, "data.txt", "r") != 0) {
		cout << "������ �������� ����� ��� ������\n";
		return 0;
	}
	
	//���������� ���������� �������
	int n;
	fscanf_s(input, "%d\n", &n);
	//cout << n << endl;
	
	//��������� ������������ ������ ��� ������ Person
	Person* list = new Person[n];
	
	//������ ������� �� ����� � ����� �� �������
	char str[MAX];
	for (int i = 0; i < n; i++) {
		fgets(str, MAX, input);
		//cout << str;
		razbor(str, list[i]); //������ ������ � ���������� i-�� �������� �������
	}
	printList(list, n); //����� ������� �� �������
	cout << endl;

	//�������� �����
	if (fclose(input) != 0) {
		cout << "������ �������� ����� ��� ������\n";
	}

	//����� ����
	int vyb;
	while (true) {
		vyb = menu();
		switch (vyb) {
		case 1: addContact(list, n); break;
		case 2: delContact(list, n); break;
		case 3: printList(list, n); break;
		case 4: printSort(list, n); break;
		case 5: findContact(list, n); break;
		case 6: findBirthdays(list, n); break;
		case 7: finish(list, n); delete[] list; return 0;
		}
	}

	//�������� ������������� ������� �� ������
	delete[] list;

	return 0;
}