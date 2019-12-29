// exam.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
/*
дано массив одномерный. вичислить среднее арифметическое индексов нулевых елементов. 
если нулевых елементов в массиве нет, то вернуть в качестве результата -1.
*/
int midarray(int a[], int n) {
	int midar = -1;
	int zeros = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			zeros += 1;
		}
	}
	cout << zeros << endl;
	if (zeros != 0) {
		for (int i = 0; i < n; i++) {		
			if (a[i] == 0) {
					midar += i;
			}			
		}
	    midar = (midar + 1) / zeros;
	}
	return midar;
}

int main()
{
	int ar[] = { 1, 2, 3, 0, 4, 9, 0, 20, 0 };
	cout << midarray(ar, 9)<<endl;
	int arr[] = { 1,2,3,4,5,7,8,9,10 };
	cout << midarray(arr, 10);
}
