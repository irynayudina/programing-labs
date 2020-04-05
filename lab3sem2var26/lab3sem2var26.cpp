﻿
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
	*str1 = '\0';
	char* str2 = new char[2*n+1];//(char*)malloc((n + 1) * sizeof(char));
	*str2 = '\0';//добавление нуля на место первого елемента массива чтобы иметь возможность конкатинировать к нему строки
	cin.getline(str1, n+1, '\n');
	cin.clear();
	cin.ignore(32767, '\n');
	char* inpStr = new char[n + 1];//(char*)malloc((n + 1) * sizeof(char)); Create copy of str1 для того чтоб иметь доступ к 
	//не измененной функцией strtok_s строке и взять из нее разделители чтоб присоеденить к измененнной строке

	strxfrm(inpStr, str1, n+1);//копировать содержимое введенной строки в другой массив чтоб иметь доступ к неизменной 
	if (*(str1 + n) != '\0') {
		cout << *(str1 + n ) << endl;
		cout << "Длинна введеной строки превышает (или не достигает) заданое вами значение." << endl <<
			"Обрабатываться будеть только та часть строки длинна которой входит в значение, остальная часть будет утеряна" << endl <<
			"Строка: " << str1 << endl;
	}
	int lenOfWord;
	cout << "Введите длинну слова" << endl;
	cin >> lenOfWord;
	cin.clear();
	cin.ignore(32767, '\n');
	const char* separators = " ,./?!|";
	char* token = nullptr, *next=nullptr;
	token = strtok_s(str1, separators, &next);//взять первый токет строки
	char* tmp = new char[lenOfWord+1];//времменая переменная для храниния обрезанного по заданной длинне токена
	strxfrm(tmp, token, lenOfWord);//сохрание нужной части токена в темп
	*(tmp + lenOfWord) = '\0';//добавление числового нуля в конце сразу после скопикованых символов токена
	strcat_s(str2, lenOfWord+1, tmp);//присоединение первого обрезанного токена к результирующей строке
	*tmp = '\0';//чтобы переписать начиная  первого елемента
	char* tmps = new char[n];//массив для времменного хранениея разделителей между токенами
	*tmps = '\0';
	int r = (token - str1 + strlen(token));//нахожу разницу между указателем на начало текущего токена и началом строки и добавляю длинну текущего токена.
			//Полученое число являеться индексом первого разделителя который стоит после текущего токена
	int e;//разница между указателем на начало следующего токена и началом строки
			//(Получинное число - 1) являеться индексом последнего разделителя который стоит после текущего токена
	int pl = 0;//индекс для записи в массив tmps 
	while (token != nullptr) {
		token = strtok_s(nullptr, separators, &next);//
		if (token != nullptr) {
			strxfrm(tmp, token, lenOfWord);//копирую содержимое токена в временную переменную с обрезанием его до заданой длинны			
			//to keep separators between tokens
			e = (token-str1);//индекс первого символа текущего токена
			pl = 0;//запись в тмпс каждый раз с первого елемента
			for (int i = r; i < e; i++) {//от первого разделителя после предыдущего токена до начала текущего токена. Скопировать все разделители между текущим и предыдущим токеном
				tmps[pl] = inpStr[i];//копировать символы разделителей в временный массив
				pl++;
			}
			r = (token - str1 + strlen(token));//обновить переменную чтоб она указывала на первый разделитель текущего токена и использовать ее значение в следующей итериции
			tmps[pl] = '\0';//освободить свободную часть не занятую символами от мусора для конкатинации
			strcat_s(str2, _TRUNCATE, tmps);//	присоединить разделители перед токеном
			strcat_s(str2, _TRUNCATE, tmp);//  присоединить токен после разделителей
			//_TRUNCATE константа позволяет копировать максимально возможную последовательность символов
			//добавляя при этом числовой ноль в конце buffer is too small exception is avoided
		}	
	}
	cout << "Преобразованная строка: " << str2 << endl;
	cout << "Изначальная строка: " << inpStr << endl;
}