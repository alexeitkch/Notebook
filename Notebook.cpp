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

//функция меню
int menu() {
	cout << "\n1 - добавить запись\n";
	cout << "2 - удалить запись\n";
	cout << "3 - вывести без сортировки\n";
	cout << "4 - вывести список, отсортированный по фамилии\n";
	cout << "5 - поиск по фамилии\n";
	cout << "6 - список именниников в определенном месяце\n";
	cout << "7 - выход из программы\n";
	int k;
	cout << "Ваш выбор: ";
	cin >> k;
	while (k < 1 || k > 7) {
		cout << "Неверный выбор! Повтрите ввод: ";
		cin >> k;
	}
	cout << endl;
	return k;
}

//функция завершения работы
void finish(Person* list, int n) {
	cout << "Завершение программы\n";
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	//открытие файла data.txt
	FILE* input = NULL;
	if (fopen_s(&input, "data.txt", "r") != 0) {
		cout << "Ошибка открытия файла для чтения\n";
		return 0;
	}
	
	//считывание количества записей
	int n;
	fscanf_s(input, "%d\n", &n);
	//cout << n << endl;
	
	//выделение динамической памяти под массив Person
	Person* list = new Person[n];
	
	//чтение записей из файла и вывод на консоль
	char str[MAX];
	for (int i = 0; i < n; i++) {
		fgets(str, MAX, input);
		//cout << str;
		razbor(str, list[i]); //разбор строки и заполнение i-го элемента массива
	}
	printList(list, n); //вывод массива на консоль
	cout << endl;

	//закрытие файла
	if (fclose(input) != 0) {
		cout << "Ошибка закрытия файла для чтения\n";
	}

	//вывод меню
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

	//удаление динамического массива из памяти
	delete[] list;

	return 0;
}