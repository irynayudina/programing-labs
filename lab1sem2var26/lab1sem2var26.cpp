#include <iostream>
#include <math.h>
#include <tgmath.h>
using namespace std;
//Функции для полиномов и их производных
double A26(double x) {
	return exp(x) - exp(-x) - 2;
}
double dA26(double x) {
	return (exp(2*x)+1)/exp(x);
}
double B26(double x) {
	return x * (tan(x)) - 0.333333333333333;//Проблема заключалалась в 1/3. Когда я заменила 1/3 на 0,333333 все стало считаться нормально
}
double dB26(double(x)) {
	return (((cos(x)) * (sin(x)) + x))/((cos(x)*cos(x)));
}
//Функция поиска корня:
double FindRoot(double (*f)(double), double x0, int imax, int &ifact, double (*df)(double)) {
	double x = x0, x1, h = 0.000001;
	x1 = x - f(x) / df(x);	
	while (fabs(x1-x)>h && ifact<=imax) {
		x = x1;
		x1 = x - f(x) / df(x);
		ifact++;
	}		
	return x1;
}
//Функция выведения результата:
void Result(double a, double b, int ifact, double x) {
	cout << "Корень " << x << " функции " << "на промежутке [" << a << ", " << b << "] найден за " << ifact << " шагов" << endl;
}
//Функция проверки на точность найденого корня
bool isRoot(double (*f)(double), double r) {
	if (f(r) < 0,00001) {
		return true;
	}
	return false;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Выберите одну из предложеных функций: A26, B26" << endl;
	string fs;
	cin >> fs;
    cout << "Введите граници промежутка [a; b]" << endl;
	double a, b;
	cin >> a;
	cin >> b;
	cout << "Введите максимальное количество итераций 3-4" << endl;
	int imax;
	cin >> imax;
	//Начальное приближение и корень:
	int ifact = 1;
	double x0, x;
	cout << "Изначальное приближенное значение корня x0 = ";
	cin >> x0;
	//Поиск решения:
	if (fs == "A26") {
		x = FindRoot(A26, x0, imax, ifact, dA26);
		if (isRoot(A26, x)) {
			Result(a, b, ifact, x);
		}
	}
	if (fs == "B26") {
		x = FindRoot(B26, x0, imax, ifact, dB26);
		if (isRoot(B26, x)) {
			Result(a, b, ifact, x);
		}
	}
}