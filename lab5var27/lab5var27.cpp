
#include <iostream>
#include <algorithm>
using namespace std;

void enterArrs(int v1[], int v2[], int v3[], const int s) {
	cout << "Ввести значення массиву v1" << endl;
	for (int i = 0; i < s; i++) {
		cout << "v1[" << i << "]" << endl;
		cin >> v1[i];
	}
	cout << "Ввести значення массиву v2" << endl;
	for (int i = 0; i < s; i++) {
		cout << "v2[" << i << "]" << endl;
		cin >> v2[i];
	}
	cout << "Ввести значення массиву v3" << endl;
	for (int i = 0; i < s; i++) {
		cout << "v3[" << i << "]" << endl;
		cin >> v3[i];
	}
}
void printArrs(int v1[], int v2[], int v3[], const int s) {
	cout << endl << "Массив v1:" << endl;
	for (int i = 0; i < s; i++) {
		cout << "v1[" << i << "] = " << v1[i] << "; ";
	}
	cout << endl << "Массив v2:" << endl;
	for (int i = 0; i < s; i++) {
		cout << "v2[" << i << "] = " << v2[i] << "; ";
	}
	cout << endl << "Массив v3:" << endl;
	for (int i = 0; i < s; i++) {
		cout << "v3[" << i << "] = " << v3[i] << "; ";
	}

}
int nzc(int a[], const int s) {
	int n = 0;
	for (int i = 0; i < s; i++) {
		if (a[i] == 0) { n += 1; }
	}
	return n;
}
int minzc(int n1, int n2, int n3) {
	int *min = 0;		
	int ar[] = { n1, n2, n3 };
	min = min_element(ar+0, ar+2);
	
	if (n3 == 0) {
		
		n1 < n2 ? *min = n1 : *min = n2;
	}
	if (n2 == 0) {
		n1 < n3 ? *min = n1 : *min = n2;
	}
	if (n1 == 0) {
		n3 < n2 ? *min = n3 : *min = n2;
	}
	if (*min == 0) {
		if (n1 == 0 && n2 == 0) {
			cout << "Только вектор 3 имеет нулевые координаты. " << "Их количество = " << n3 << endl;
		}
		if (n1 == 0 && n3 == 0) {
			cout << "Только вектор 2 имеет нулевые координаты. " << "Их количество = " << n2 << endl;
		}
		if (n3 == 0 && n2 == 0) {
			cout << "Только вектор 1 имеет нулевые координаты. " << "Их количество = " << n1 << endl;
		}
	}
	return *min;
}

void tArr(int a1[], const int s ) {
	for (int i = 0; i < s; i++) {
		if (a1[i] == 0) {
			for (int u = i; u > 0; u--) {
				a1[u] = a1[u-1];
			}
			a1[0] = 0;
		}


	}
}
int main()
{
	setlocale(LC_ALL, "ukr");
	const int s = 5;
	int numZ1=0, numZ2=0, numZ3=0, minN=0;
	int v1[s];
	int v2[s];
	int v3[s];
	
	// void enterArrs()
	enterArrs(v1, v2, v3, s);
    // void printArrs()
	printArrs(v1, v2, v3, s);
	// int nZeroCoords
	numZ1 = nzc(v1, s);
	numZ2 = nzc(v2, s);
	numZ3 = nzc(v3, s);
	cout << endl << "Количество нулей в векторе v1: " << numZ1 << endl;
	cout << "Количество нулей в векторе v2: " << numZ2 << endl;
	cout << "Количество нулей в векторе v3: " << numZ3 << endl;
		
	// int minNZC
	if (minzc(numZ1, numZ2, numZ3) != 0) {
		cout << "Минимальное количество нулевых координат( из тех векторов, где они есть): " << minzc(numZ1, numZ2, numZ3);
	}
	// transfer to the beggining
	tArr(v1, s);
	tArr(v2, s);
	tArr(v3, s);
	printArrs(v1, v2, v3, s);
    

}

