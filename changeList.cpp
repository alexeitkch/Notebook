#include "changeList.h"
#include "definitions.h"
#include <iostream>
using namespace std;

void addContact(Person*& list, int& n) {
	//выделение новой пам€ти под массив размера n+1
	Person* newList = new Person[n + 1];
	//копирование всех данных из исходного массива в новый
	for (int i = 0; i < n; i++) {
		newList[i] = list[i];
	}
	//запрашиваем у пользовател€ данные новго контакта, добавл€ем в конец мыссива
	cout << "¬ведите фамилию: ";
	cin >> newList[n].secondName;
	cout << "¬ведите им€: ";
	cin >> newList[n].name;
	cout << "¬ведите телефон: ";
	cin >> newList[n].telefon;
	cout << "¬ведите день, мес€ц и год рождени€ через пробел: ";
	cin >> newList[n].birthday.day;
	cin >> newList[n].birthday.month;
	cin >> newList[n].birthday.year;
	//исходный массив из пам€ти удал€ем
	delete[] list;
	//новый массив переименовываем в list
	list = newList;
	n++;
}
void delContact(Person*& list, int& n) {
	cout << "”даление контакта\n";
}