// Файл functions
#include "Functions.h"


vector<int> selectionSort(vector<int> array) {
	int min;
	vector<int> sortArray=array;
	int minI = 0;
	int q = 0; // Объявление необходимых переменных
	for (int i = 0; i < sortArray.size(); i++) { // Цикл по всему массиву
		min = INT_MAX; // Инициализация минимального числа
		for (int j = i; j < sortArray.size(); j++) { // Цикл поиска минимального значения для вставки
			if (sortArray[j] < min) {
				min = sortArray[j];
				minI = j;
			}
		}
		if (sortArray[minI] != sortArray[i]) { // Проверка, что найденное минимальное число не стоит в месте для вставки
			swap(sortArray[minI], sortArray[i]); // Свап найденного минимума и первого неотсортированного элемента
		}
	}
	return sortArray; // Возврат из функции отсортированного массива
}

int isNumber() { // Функция проверки корректности ввода пользователя
	int userInput;
	cin >> userInput;
	if (cin.fail() or userInput <= 0) { // Если ошибка ввода( в инт не может записать не целое число) или ввод <=0
		cout << "Ввод неверный. Повторите ввод." << endl;
		while (cin.fail() or userInput <= 0) { // Пока сохраняется ошибка
			cin.clear(); // Очистка флага ошибки чтения
			cin.ignore(INT_MAX, '\n'); // Очистка неправильно введенной строчки
			cout << "Введите число:"; cin >> userInput; cout << endl; // Повторный ввод
		}
	}
	cin.ignore(INT_MAX, '\n'); 
	return userInput;
}

int isNumber(int i,int j) {  // Перегрузка предыдущей функции для работы с двумя конкретными числами
	int userInput;
	cin >> userInput;
	if (cin.fail() or userInput < 0 and (userInput!=i and userInput != j)) {
		cout << "Ввод неверный. Повторите ввод." << endl;
		while (cin.fail() or userInput < 0 and (userInput != i and userInput != j)) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Введите число:"; cin >> userInput; cout << endl;
		}
	}
	cin.ignore(INT_MAX, '\n');
	return userInput;
}
