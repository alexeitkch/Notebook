#include "print.h"
#include "definitions.h"
#include <iostream>
#include <iomanip>
using namespace std;

//вывод на консоль данных одного человека
void print(Person* item) {
	cout << item->secondName << " " << item->name << " тел.: " << item->telefon;
	cout << "\n\t" << setw(2) << setfill('0') << item->birthday.day << "." << setw(2) << setfill('0') << item->birthday.month << "." << item->birthday.year << endl;
}

void printList(Person* list, int n) {
	system("cls"); //отчистка экрана
	cout << "Содержание записной книжки:\n";
	for (int i = 0; i < n; i++) {
		print(&list[i]);
	}
	cout << endl;
}

void printSort(Person* list, int n) {
	system("cls"); //отчистка экрана
	cout << "Сортировка по фамилии\n";
	//создание и инициализация массива указателей
	Person** ptr = new Person * [n];
	for (int i = 0; i < n; i++) {
		ptr[i] = &list[i];
	}

	//сортировака массива указателеей
	for (int k = n - 1; k > 0; k--) {
		for (int i = 0; i < k; i++) {
			if (strcmp(ptr[i]->secondName, ptr[i + 1]->secondName) > 0) {
				Person* tmp = ptr[i];
				ptr[i] = ptr[i + 1];
				ptr[i + 1] = tmp;
			}
		}
	}

	//вывод на консоль
	for (int i = 0; i < n; i++) {
		print(ptr[i]);
	}

	//удаление массива указателей
	delete[] ptr;
}