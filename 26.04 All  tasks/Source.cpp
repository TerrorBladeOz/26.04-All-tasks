#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
const int l = 4, h = 4;
//Нашел 2 алгоритма циклического сдвига вправо и вниз, а влево и вверх сделал сам.
void right(double** Neo, int n)//вправо
{
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < h; i++) {
			double t = Neo[i][l - 1];
			int j;
			for (j = h - 1; j > 0; j--) {
				Neo[i][j] = Neo[i][j - 1];
			}
			Neo[i][j] = t;
		}
	}
}
void down(double** Neo, int n)//вниз
{
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < h; i++) {
			double t = Neo[l - 1][i];
			int j;
			for (j = l - 1; j > 0; j--) {
				Neo[j][i] = Neo[j - 1][i];
			}
			Neo[j][i] = t;
		}
	}
}
void left(double** Neo, int n)//долго пытался, но так и не додумался  
{
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < h; i++) {
			double t = Neo[i][l - 4];
			int j;
			for (j = h -  1; j > 0; j--) {
				Neo[i][j] = Neo[i][j - 4];
			}
			Neo[i][j] = t;
		}
	}
}
void up(double** Neo, int n)//вверх
{	
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < h; ++i) {
			double t = Neo[l - 1][i];
			int j;
			for (j = l - 1; j > 0; --j)
				Neo[j][i] = Neo[j - 1][i];
				Neo[0][i] = t;
			
		}
	}
}
void main()
{
	setlocale(LC_ALL, "rus");
	int c;
	const int a = 5, b = 5;
	int li[a][b];
	int v;
	cout << "Чтобы остоновить напишите 0 !!!\n";
	do {
		cout << "Какое задание 1 - 3 ?\n";
		cin >> c;
		switch (c)
		{
		case 0:
			cout << "\nПрограмма закончена !!! \n";
		case 1:
			cout << "Введите число: ";
			cin >> v;
			for (int i = 0; i < a; i++)
			{
				cout << "||| ";
				for (int j = 0; j < b; j++)
				{
					li[a][b] = v;
					v *= 2;
					cout << li[a][b] << " ";
				}
				cout << " |||\n";
			}
			break;
		case 2:
			cout << "Введите число: ";
			cin >> v;
			for (int i = 0; i < a; i++)
			{
				cout << "||| ";
				for (int j = 0; j < b; j++)
				{
					li[a][b] = v++;
					cout << li[a][b] << " ";
				}
				cout << " |||\n";
			}
			break;
		case 3:
			int n;
			int a;
			double** Neo;
			Neo = new double* [l];
			for (int i = 0; i < l; i++) {
				Neo[i] = new double[h];
			}

			for (int i = 0; i < h; i++) {
				cout << "|||  ";
				for (int j = 0; j < l; j++) {
					Neo[i][j] = 0 + rand() % 23;
					cout << Neo[i][j] << " ";
				}
				cout << "  |||";
				cout << endl;
			}

			cout << "На сколько сдвинуть: \n";
			cin >> n;
			cout << "Куда сдвинуть 0 - вправо, 1 - влево, 2 - вниз, 3 - вверх >>> ";
			cin >> a;
			if (a == 0) {
				right(Neo, n);
			}
			else if (a == 1) {
				left(Neo, n);

			}
			else if (a == 2) {
				down(Neo, n);
			}
			else if (a == 3) {
				up(Neo, n);
			}
			cout << "\n" << "Вывод матрицы с сдвигом > > >" << "\n";
			for (int i = 0; i < l; i++)
			{
				cout << "|||  ";
				for (int j = 0; j < h; j++) {
					cout << Neo[i][j] << " ";
				}
				cout << "  |||";
				cout << "\n";
			}
			for (int i = 0; i < l; i++) {//удаление массива из памяти
				delete[]Neo[i];
			}
			delete[] Neo;
			break;
		default:
			cout << "\nПовторите ввод\n";
		}
	} 	while (c != 0);
}