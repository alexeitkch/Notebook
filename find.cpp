#include "find.h"
#include "definitions.h"
#include "print.h"
#include <iostream>
#include <iomanip>
using namespace std;

void findContact(Person* list, int n) {
	char nameGiven[MAX];
	cout << "¬ведите фамилию: ";
	cin >> nameGiven;
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(list[i].secondName, nameGiven) == 0) {
			if (k == 0) {
				cout << "–езультаты поиска:\n";
			}
			print(&list[i]);
			k++;
		}
	}
	if (k == 0) {
		cout << " онтакты не найдены\n";
	}
	system("pause");
	system("cls"); //отчистка экрана
}

void findBirthdays(Person* list, int n) {
	//ввод мес€ца
	int month;
	cout << "¬ведите номер мес€ца: ";
	cin >> month;
	//подсчет количества контактов в этом мес€це
	int kol = 0;
	for (int i = 0; i < n; i++) {
		if (list[i].birthday.month == month) {
			kol++;
		}
	}
	if (kol == 0) {
		cout << "¬ этом мес€це именниников нет!\n";
		return;
	}
	//выделение динамической пам€ти и заполнение массива указателей
	Person** ptr = new Person * [kol];
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (list[i].birthday.month == month) {
			ptr[j++] = &list[i];
		}
	}
	//сортировка массива указателей
	for (int k = kol - 1; k > 0; k--) {
		for (int i = 0; i < k; i++) {
			if (ptr[i]->birthday.day > ptr[i + 1]->birthday.day) {
				Person* tmp = ptr[i];
				ptr[i] = ptr[i + 1];
				ptr[i + 1] = tmp;
			}
		}
	}
	//вывод контактов
	cout << "»менниники в этом мес€це:\n";
	for (int i = 0; i < kol; i++) {
		print(ptr[i]);
	}
	//удаление массива указателей
	delete[] ptr;
	system("pause");
	system("cls"); //отчистка экрана
}