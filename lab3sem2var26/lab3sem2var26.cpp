
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <Windows.h>
using namespace std;

int main()
{
    /*
    Юдіна Ірина 
    ПЗ-19-2
    Лабораторна робота №3 семестр 2
    Варіант 27
	Группа А
	Скласти і налагодити програму, яка у довільному реченні скорочує (шляхом стиснення)
	всі слова до заданої довжини (вводиться за запитом),
	зберігаючи розділові знаки.
    */   
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << "Введите длинну строки" << endl;
	cin >> n;
	cin.clear();
	cin.ignore(32767, '\n');
	cout << "Введите строку для анализа" << endl;
	char* str1 = new char[n+1];//(char*)malloc((n + 1) * sizeof(char));///	
	char* str2 = new char[2*n+1];//(char*)malloc((n + 1) * sizeof(char));
	*str2 = '\0';
	cin.getline(str1, n+1, '\n');
	cin.clear();
	cin.ignore(32767, '\n');
	char* inpStr = new char[n + 1];//(char*)malloc((n + 1) * sizeof(char)); Create copy of str1 для того чтоб иметь доступ к 
	//не измененной функцией strtok_s строке и взять из нее разделители чтоб присоеденить к измененнной строке
	strxfrm(inpStr, str1, n+1);
	if (*(str1 + n + 1) != '\n') {
		cout << "Длинна введеной строки превышает заданое вами значение." << endl <<
			"Обрабатываться будеть только та часть строки длинна которой входит в значение, остальная часть будет утеряна" << endl <<
			"Строка: " << str1 << endl;
	}
	int lenOfWord = 4;
	cout << "Введите длинну слова" << endl;
	cin >> lenOfWord;
	cin.clear();
	cin.ignore(32767, '\n');
	const char* separators = " ,./?!|";
	char* token = nullptr, *next=nullptr;
	token = strtok_s(str1, separators, &next);
	//cout << "Original str1 after extructing 1st token: " << str1 << endl;
	char* tmp = new char[lenOfWord+1];
	strxfrm(tmp, token, lenOfWord);
	*(tmp + lenOfWord) = '\0';
	strcat_s(str2, lenOfWord+1, tmp);
	*tmp = '\0';
	char* tmps = new char[n];//максимально возможная длинна если один токен а все остальное разделители
	*tmps = '\0';//массив ля хранениея разделителей между токенами
	int r = (token - str1 + strlen(token));//нахожу разницу между указателем на начало текущего токена и началом строки и добавляю длинну текущего токена.
			//Полученое число являеться индексом первого разделителя который стоит после текущего токена
	int e = (next - str1);//разница между указателем на начало следующего токена и гачалом строки
			//Получинное число - 1 являеться индексом последнего разделителя который стоит после текущего токена
	int pl = 0;//индекс для записи в массив tmps 
	for (int i = r; i < e; i++) {
		tmps[pl] = inpStr[i];//заполнение массива разделителями
		pl++;
	}
	tmps[pl] = '\0';
	strcat_s(str2, _TRUNCATE, tmps);
	*tmp = '\0';
	//strcat_s(str2, _TRUNCATE, tmps);
	//int sbeg = strlen(token);
	while (token != nullptr) {
		token = strtok_s(nullptr, separators, &next);
		if (token != nullptr) {
			strxfrm(tmp, token, lenOfWord);//копирую содержимое токена в временную переменную с обрезанием его до заданой длинны
			strcat_s(str2, _TRUNCATE, tmp);//константа позволяет копировать максимально возможную последовательность символов
			//добавляя при eтом числовой ноль в конце buffer is too small exception is avoided
			//to keep separators between tokens
			r = (token - str1 + strlen(token));
			e = (next - str1);
			pl = 0;
			for (int i = r; i < e; i++) {
				tmps[pl] = inpStr[i];
				pl++;
			}
			tmps[pl] = '\0';
			strcat_s(str2, _TRUNCATE, tmps);	
			*tmp = '\0';
		}
	
	}
	cout << "Преобразованная строка: " << str2 << endl;
	cout << "Изначальная строка: " << inpStr << endl;
}