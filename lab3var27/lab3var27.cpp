
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int sum = 0;
	int sum1 = 0;
	const int size = 10;
	double arr[size];

	for (int i = 0; i < size; i++) {
		cout << "Ввевсти зачение переменной " << i+1 <<" массива" << endl;
		cin >> arr[i];
	}
	cout << "Массив: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << "Сума индексов  положительных элементов, стоящих на нечетных местах в массиве: ";
	for (int i = 0; i < size; i +=2) {
		if (arr[i] > 0) {
			sum += i;
		}
	}
	cout << sum << endl;	

	for (int i = 1; i < size; i++) {
		for (int k = i; k > 0 && arr[k - 1] > arr[k]; k--) {
		double temp = arr[k - 1];
			arr[k - 1] = arr[k];
			arr[k] = temp;
		}
	}
	cout << "Отсортированый массив: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << "Сумма модулей минимального и максимального значений: ";
	sum1 = abs(arr[0]) + abs(arr[9]);
	cout << sum1 << endl;
}

