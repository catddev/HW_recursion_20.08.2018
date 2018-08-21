//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
#include <algorithm>

using namespace std;

// Решить все задачи с применением рекурсии :

// 1.	Написать функцию, определяющую среднее арифметическое элементов
// передаваемого ей массива.
template<typename type>
double average(type a[], int n) {
	if (n == 1) return a[n - 1];
	return (a[n - 1] + average(a, n - 1)*(n - 1)) / n;
}

// 2.	Написать функцию, определяющую количество положительных,
// отрицательных и нулевых элементов передаваемого ей массива.
//template<typename type>
//void fpmz(type b[], int n) {
//	int p = 0, m = 0, z = 0;
//
//	type arr[];
//	for (int i = 0; i < n; i++)
//		arr[i]=b[i];
//
//	int size = n;
//	int pmz = 0;
//
template<typename type>
int count_pmz(type arr[], int size, int &pmz) {
	if (size == 1)
	{
		if (arr[size - 1] < 0)
			return pmz += 100;

		else if (arr[size - 1] > 0)
			return pmz += 10;

		else if (arr[size - 1] == 0)
			return pmz += 1;
	}

	else
	{
		if arr[size - 1] < 0)
		return pmz + 100 + count_pmz(arr, size - 1);

		else if (arr[size - 1] > 0)
			return pmz + 10 + count_pmz(arr, size - 1);

		else if (arr[size - 1] == 0)
			return pmz + 1 + count_pmz(arr, size - 1);
	}
}
//	cout << "- elements: " << pmz << endl;
//	/*cout << "+ elements: " << p << endl;
//	cout << "zeros: " << z << endl << endl;*/
//}



// 3.	Написать функцию, определяющую минимум и максимум(значение и номер)
// элементов передаваемого ей массива.
int position(int arr[], int size, int &min, int &max, int &pos_min, int pos_max) {

	if (size == 1)
	{
		cout << min << " ," << pos_min << endl;
		cout << max << " ," << pos_max << endl << endl;
		return 1;

		if (arr[size - 1] < min)
		{
			min = arr[size - 1];
			pos_min = size - 1;
			return position(arr, size - 1, min, max, pos_min, pos_max);
		}
		if (arr[size - 1] > max)
		{
			max = arr[size - 1];
			pos_max = size - 1;
			return position(arr, size - 1, min, max, pos_min, pos_max);
		}
	}
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
			double a[7] = { 1.5, -2.5, -3.5, 4.5, 0, 6.5, 7.5 };
			int b[] = { -1, 0, 3, 0, 5, 6, 0 };

			/*fpmz(a, 7);
			fpmz(b, 7);*/
			int pmz = 0;

			cout << count_pmz(b, 7, pmz) << endl << endl;
		}
		break;
		case 3:
		{
			double a[7] = { 1.5, -2.5, -3.5, 4.5, 0, 6.5, 7.5 };
			int b[] = { -1, 0, 3, 0, 5, 6, 0 };

			int min = INT_MAX;
			int max = INT_MIN;
			int pos_min = 0;
			int pos_max = 0;
			cout << position(b, 7, min, max, pos_min, pos_max) << endl;
		}
		break;
		case 4:
		{

		}
		break;
		case 5:
		{

		}
		break;
		case 6:
		{

		}
		break;
		case 7:
		{

		}
		break;
		case 8:
		{

		}
		break;
		case 9:
		{

		}
		break;
		case 10:
		{

		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}