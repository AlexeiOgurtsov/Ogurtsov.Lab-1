#include<iostream>
#include<bitset>
using namespace std;

double* AllocArray(int n);
void BubbleSort(double* a, int n);
void DisplayArray(double* a, int n);
void Swap(double &x, double &y);
int NumberOfOne(double a);
int NumberOfZero(double a);
void DisplayBinaryNumber(double* a, int n);
void DisplayNumberOfOne(double* a, int n);
void DisplayNumberOfZero(double* a, int n);
int NumberOfZero(double a);
void IsDataValidSize(int &n);
void IsDataValidNumber(int &t);
double* OtherArray(double* a, int t, int y, int &n, int &r);

int main(){
	while (true){
		int n, t, y;
		IsDataValidSize(n);
		system("cls");
		IsDataValidNumber(t);
		system("cls");
		IsDataValidNumber(y);
		system("cls");
		double* a = AllocArray(n);
		system("cls");
		DisplayArray(a, n);
		cout << " -Initial array" << endl;
		cout << "-----------------------------------------" << endl;
		DisplayBinaryNumber(a, n);
		cout << endl;
		cout << "-----------------------------------------" << endl;
		DisplayNumberOfOne(a, n);
		cout << endl;
		DisplayNumberOfZero(a, n);
		cout << endl;
		cout << "-----------------------------------------" << endl;
		BubbleSort(a, n);
		DisplayArray(a, n);
		cout << " -Sorted array" << endl;
		cout << "-----------------------------------------" << endl;
		int m = 0;
		int l = 0;
		int r = 0;
		double* b = OtherArray(a, t, y, n, r);
		DisplayArray(b, r);
		cout << "-Other Array" << endl;
		cout << "-----------------------------------------" << endl;
		DisplayArray(a, n);
		cout << "-Initial(reversed) array" << endl << endl;
		delete[] a;
		delete[] b;
		int w;
		cout << "Do you want to continue?" << endl;
		cout << "1.Yes" << endl;
		cout << "2.No" << endl;
		cin >> w;
		if (w == 2) return 0;
		system("cls");
		continue;
	}
}
double* AllocArray(int n)
{
	double* a = new double[n];
	for (double *i = a, j = 1; i < a + n; i++, j++)
	{
		cout << "Enter " << j << "element of array:";
		cin >> *i;
	}
	return a;
}

void BubbleSort(double* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{

			if (NumberOfOne(a[j]) > NumberOfOne(a[j + 1]))
				Swap(a[j], a[j + 1]);
		}
	}
}

double* OtherArray(double* a, int t, int y, int &n, int &r)
{
	double *b = new double[n];
	int k = 0;
	for (int p = 0; p < n; p++)
	{
		if (NumberOfOne(a[p]) == t && NumberOfZero(a[p]) == y)
			r++;
	}
	for (int i = 0, j = 0; i < n; i++)
	{
		if (NumberOfOne(a[i]) == t && NumberOfZero(a[i]) == y)
		{
			b[j] = a[i];
			j++;
			k++;
			for (int q = i; q < n; q++)
			{
				a[q] = a[q + 1];
			}
			n--;
			i--;
		}
	}
	return b;
}

void Swap(double &x, double &y)
{
	double temp = x;
	x = y;
	y = temp;
}

int NumberOfOne(double a)
{
	int i = 0;
	int c = a / 2;
	int d = a - c * 2;
	if (a == 1)
	{
		return 1;
	}
	while (c)
	{
		c = a / 2;
		d = a - c * 2;
		if (d == 1)
			i++;
		a = c;
	}
	return i;
}

int NumberOfZero(double a)
{
	int i = 0;
	int c = a / 2;
	int d = a - c * 2;
	if (a == 0)
	{
		return 1;
	}
	while (c)
	{
		c = a / 2;
		d = a - c * 2;
		if (d == 0)
			i++;
		a = c;
	}
	return i;
}

void DisplayArray(double* a, int n)
{
	for (double *i = a; i < a + n; i++)
		cout << *i << "     ";
}

void DisplayBinaryNumber(double* a, int n)
{
	for (double *i = a; i < a + n; i++)
		cout << bitset<8>(*i) << "     ";
	cout << "-Binary view of Initial array";
}

void DisplayNumberOfOne(double* a, int n)
{
	for (double *i = a; i < a + n; i++)
		cout << NumberOfOne(*i) << "     ";
	cout << "   -Number of 1 in the array elements";
}

void DisplayNumberOfZero(double* a, int n)
{
	for (double *i = a; i < a + n; i++)
		cout << NumberOfZero(*i) << "     ";
	cout << "   -Number of 0 in the array elements";
}

void IsDataValidSize(int &n)
{
	while (true)
	{
		cout << "Enter integer size of Array(size > 0):";
		cin >> n;
		if (n <= 0)
		{
			system("cls");
			continue;
		}
		break;
	}
}

void IsDataValidNumber(int &t)
{
	while (true)
	{
		cout << "Enter integer number of 1(Number of > 0):";
		cin >> t;
		if (t < 0)
		{
			system("cls");
			continue;
		}
		break;
	}
}
