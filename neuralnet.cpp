// neuralnet.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h> 
#include <vector>
#include <time.h> 

using namespace std;

int *weights = new int[15]; //веса сети
int bias = 7; //порог функции активации

//является ли данное число 6
bool proceed(char* number)
{
	int net = 0;
	//взвешенная сумма
	for (int i = 0; i < 15; i++)
	{
		int n = number[i] - '0';
		net += n * weights[i];
	}
	//если взвешенная сумма превышает порог, то сеть думает, что это 6
	return net >= bias;
}

//уменьшение значений весов, если сеть ошиблась и посчитала 6 не ее
void decrease(char* number)
{
	for (int i = 0; i < 15; i++)
	{
		int n = number[i] - '0';
		//если вход был возбужден, то уменьшаем связанный с ним вес
		if (n == 1)
		{
			weights[i]--;
		}
	}
}

//увеличение значений весов, если сеть ошиблась, и не признала 6
void increase(char* number)
{
	for (int i = 0; i < 15; i++)
	{
		int n = number[i] - '0';
		//если вход был возбужден, то увеличиваем связанный с ним вес
		if (n == 1)
		{
			weights[i]++;
		}
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL,"Rus");

	//инициализация весов
	for (int i = 0; i < 15; i++)
	{
		weights[i] = 0;
	}

	//подготовка цифр
	char num0[15] = { '1','1','1','1','0','1','1','0','1','1','0','1','1','1','1' },
		num1[15] = { '0','0','1','0','0','1','0','0','1','0','0','1','0','0','1' },
		num2[15] = { '1','1','1','0','0','1','1','1','1','1','0','0','1','1','1' },
		num3[15] = { '1','1','1','0','0','1','1','1','1','0','0','1','1','1','1' },
		num4[15] = { '1','0','1','1','0','1','1','1','1','0','0','1','0','0','1' },
		num5[15] = { '1','1','1','1','0','0','1','1','1','0','0','1','1','1','1' },
		num6[15] = { '1','1','1','1','0','0','1','1','1','1','0','1','1','1','1' },
		num7[15] = { '1','1','1','0','0','1','0','0','1','0','0','1','0','0','1' },
		num8[15] = { '1','1','1','1','0','1','1','1','1','1','0','1','1','1','1' },
		num9[15] = { '1','1','1','1','0','1','1','1','1','0','0','1','1','1','1' };

	vector<char*> nums;
	nums.push_back(num0);
	nums.push_back(num1);
	nums.push_back(num2);
	nums.push_back(num3);
	nums.push_back(num4);
	nums.push_back(num5);
	nums.push_back(num6);
	nums.push_back(num7);
	nums.push_back(num8);
	nums.push_back(num9);

	//подготовка тестовой выборки
	char num61[15] = { '0','1','1','1','0','0','1','1','1','1','0','1','1','1','1' },
		num62[15] = { '1','1','1','1','0','0','1','1','0','1','0','1','1','1','1' },
		num63[15] = { '1','1','1','1','0','0','1','1','1','1','0','1','1','1','0' },
		num64[15] = { '1','1','1','1','0','0','1','1','0','1','0','1','1','1','0' };

	vector<char*> test;
	test.push_back(num61);
	test.push_back(num62);
	test.push_back(num63);
	test.push_back(num64);

	cout << "Рисунки цифр" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "Цифра" << i << endl;
		int k = 0;
		for (int j = 0; j < 5; j++)
		{
			cout << nums[i][k]; k++;
			cout << nums[i][k]; k++;
			cout << nums[i][k]; k++;
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;

	//обучение сети
	for (int i = 0; i < 10000; i++)
	{
		//выбираем случаную цифру
		int option = rand()%9;
		//проверяем, является ли она 6. Если нет то
		if (option != 6)
		{
			//если она распознается сетью как 6, то уменьшаем веса
			if (proceed(nums[option])) 
				decrease(nums[option]);
		}
		else
		{
			//если это 6, но она не распозналась сетью, то увеличиваем веса
			if (!proceed(num6)) 
				increase(num6);
		}
	}

	cout << "Веса обученной сети:" << endl;
	for (int i = 0; i < 15; i++)
	{
		cout << weights[i] << " ";
	}
	cout << endl;

	//Проверка обученной сети, 1-правда, 0-неправда
	for (int i = 0; i < 10; i++)
	{
		cout << i << " это 6 - " << proceed(nums[i])<<endl;
	}

	for (int i = 0; i < 4; i++)
	{
		cout << "Искаженная 6 то 6 - " << proceed(test[i])<<endl;
	}

	system("pause");
    return 0;
}

