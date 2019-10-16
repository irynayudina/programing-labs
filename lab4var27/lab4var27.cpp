
#include <iostream>
using namespace std;
#include <cstdlib>

int main()
{   	
    int m = 3, n = 4;
	cout << "Given matrix m*n. Enter m: "; cin >> m;
	cout << "Enter (3 or 4 or 5) n: "; cin >> n;
	cout << "Array a: " << endl;
	int* b = new int[n];
	double** a = new double*[m];
	double** a1 = new double* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new double[n];
		a1[i] = new double[n];
		for (int ii = 0; ii < n; ii++) {
			a[i][ii] = static_cast<double>(ii + 1) / 2;
			a1[i][ii] = static_cast<double>(ii + 1) / 2;
			//b[ii] = ii + 1;
			cout << a[i][ii] << "   ";
		}
		cout << endl;
	}	
	

	srand(n);
	/*for (int i = 0; i < n; i++) {
		int ib = 0 + rand() % (n-1);
		int ib1 = 0 + rand() % (n-1);
		swap(b[ib], b[ib1]);
	}*/
	switch (n){
	    case 3: b[0] = 1; b[1] = 3; b[2] = 2; break;
		case 4: b[0] = 3; b[1] = 4; b[2] = 1; b[3] = 2; break;
		case 5: b[0] = 4; b[1] = 1; b[2] = 5; b[3] = 2; b[4] = 3; break;
	}
	cout << "Vector b: " << endl;
	for (int i3 = 0; i3 < n; i3++) {
		cout << b[i3] << " ";
	}
	cout << endl;


	cout << "Array a sorted: " << endl;
	for (int i4 = 0; i4 < m; i4++) {
		for (int i5 = 0; i5 < n; i5++) {
			a[i4][i5] = a1[i4][b[i5]-1];
			cout << a[i4][i5] << "  ";
		}
		cout << endl;
	}


	for (int i = 0; i < m; i++) {
		delete[] a[i];
		delete[] a1[i];
	}
	delete[] a; delete[] a1;
	 
	/*double arr[3][4] = { {0.5, 1, 1.5, 2}, {0.5, 1, 1.5, 2}, {0.5, 1, 1.5, 2} };
	double arr1[3][4] = { {0.5, 1, 1.5, 2}, {0.5, 1, 1.5, 2}, {0.5, 1, 1.5, 2} };
	int b[4] = { 0, 3, 2, 1 };
	for (int i = 0; i <= 2; i++) {
		for (int y = 0; y <= 3; y++) {					
            arr[i][y] = arr1[i][b[y]];			
		}
		cout << endl;
	}
	*/
}

