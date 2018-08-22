//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
#include <algorithm>

using namespace std;

// 1.	Написать функцию, определяющую среднее арифметическое элементов
// передаваемого ей массива.
template<typename type>
double average(type a[], int n) {
	if (n == 1) return a[n - 1];
	return (a[n - 1] + average(a, n - 1)*(n - 1)) / n;
}

// 2.	Написать функцию, определяющую количество положительных,
// отрицательных и нулевых элементов передаваемого ей массива.
template<typename type> // case 2
void count_pmz(type arr[], int size, int &p, int &m, int &z) {
	if (size == 1)
	{
		if (arr[size - 1] < 0)
			m++;

		else if (arr[size - 1] > 0)
			p++;

		else if (arr[size - 1] == 0)
			z++;
	}

	else
	{
		if (arr[size - 1] < 0)
		{
			m++;
			count_pmz(arr, size - 1, p, m, z);
		}
		else if (arr[size - 1] > 0)
		{
			p++;
			count_pmz(arr, size - 1, p, m, z);
		}
		else if (arr[size - 1] == 0)
		{
			z++;
			count_pmz(arr, size - 1, p, m, z);
		}
	}
}

// 3.	Написать функцию, определяющую минимум и максимум(значение и номер)
// элементов передаваемого ей массива.
// case 10
template<typename type>
void posMinMax(type arr[], int size) {
	static type min = arr[0];
	static type max = arr[0];
	static int pos_min = 0;
	static int pos_max = 0;

	if (size == 0)
	{
		cout << "min element: " << min << ", its position: " << pos_min << endl;
		cout << "max element: " << max << ", its position: " << pos_max << endl << endl;
		return;
	}

	if (arr[size - 1] < min)
	{
		min = arr[size - 1];
		pos_min = size - 1;
	}
	if (arr[size - 1] > max)
	{
		max = arr[size - 1];
		pos_max = size - 1;
	}
	posMinMax(arr, size - 1); // recursion
}

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 1:
		{
			double a[8] = { 2, 4.2, 6.4, 8, 10, 12.8, 14.5, 16 };

			cout << average(a, 8) << endl << endl;

		}
		break;
		case 2:
		{
			int k[] = { -1, 0, 3, 0, 5, 6, 7, 0 };
			int a = 0, b = 0, c = 0;

			count_pmz(k, 8, a, b, c);

			cout << "positive elements: " << a << endl;
			cout << "negative elements: " << b << endl;
			cout << "zero elements: " << c << endl << endl;

			int a1 = 0, b1 = 0, c1 = 0;
			double r[7] = { 1.5, -2.5, -3.5, 4.5, 0, 6.5, 7.5 };

			count_pmz(r, 7, a1, b1, c1);

			cout << "positive elements: " << a1 << endl;
			cout << "negative elements: " << b1 << endl;
			cout << "zero elements: " << c1 << endl << endl;
		}
		break;
		case 3:
		{
			double a[7] = { 1.5, -2.5, -3.5, 4.5, 0, 8.5, 7.5 };
			int b[] = { 1, 2, 3, 4, 5, 6, 7 };

			posMinMax(b, 7);

			posMinMax(a, 7);
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}