#include<iostream>
#include<bitset>
using namespace std;

double* allocArray(int n);
void bubbleSort(double* a, int n);
void displayArray(double* a, int n);
void swap(double &x, double &y);
int numberOfOne(double a);
int numberOfZero(double a);
void displayBinaryNumber(double* a, int n);
void displayNumberOfOne(double* a, int n);
void displayNumberOfZero(double* a, int n);
int numberOfZero(double a);
void isDataValidSize(int &n);
void isDataValidNumber(int &t);
double* otherArray(double* a, int t, int y, int n, int &m, int &l);
void reversedInitialArray(double* a, int n, int m, int l);

int main(){
loop: // GOTO use to reusable console
	system("cls");
	int n, t, y;
	isDataValidSize(n);
	system("cls");
	isDataValidNumber(t);
	system("cls");
	isDataValidNumber(y);
	system("cls");
	double* a = allocArray(n);
	system("cls");
	displayArray(a, n);
	cout << " -Initial array" << endl;
	cout << "-----------------------------------------" << endl;
	displayBinaryNumber(a, n);
	cout << endl;
	cout << "-----------------------------------------" << endl;
	displayNumberOfOne(a, n);
	cout << endl;
	displayNumberOfZero(a, n);
	cout << endl;
	cout << "-----------------------------------------" << endl;
	bubbleSort(a, n);
	displayArray(a, n);
	cout << " -Sorted array" << endl;
	cout << "-----------------------------------------" << endl;
	int m = 0;
	int l = 0;
	double* b = otherArray(a, t, y, n, m, l);
	displayArray(b, m);
	cout << "-Other Array" << endl;
	reversedInitialArray(a, n, m, l);
	cout << "-----------------------------------------" << endl;
	displayArray(a, n - m);
	cout << "-Initial(reversed) array" << endl << endl;
	int w;
	cout << "Do you want to continue?" << endl;
	cout << "1.Yes" << endl;
	cout << "2.No" << endl;
	cin >> w;
	if (w == 1) goto loop;
	return 0;
}
double* allocArray(int n)
{
	double* a = new double[n];
	for (double *i = a, j = 1; i < a + n; i++, j++)
	{
		cout << "Enter " << j << "element of array:";
		cin >> *i;
	}
	return a;
}

void bubbleSort(double* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{

			if (numberOfOne(a[j]) > numberOfOne(a[j + 1]))
				swap(a[j], a[j + 1]);
		}
	}
}

double* otherArray(double* a, int t, int y, int n, int &m, int &l)
{
	double *b = new double[n];
	int k = 0;
	for (int i = 0, j = 0; i < n; i++)
	{
		if (numberOfOne(a[i]) == t && numberOfZero(a[i]) == y)
		{
			b[j] = a[i];
			j++;
			k++;
			l = i;
		}
	}
	m = k;
	return b;
}

void reversedInitialArray(double* a, int n, int m, int l)
{
	for (int i = l; i < n - m; i++)
		a[i] = a[i + m];
}

void swap(double &x, double &y)
{
	double temp = x;
	x = y;
	y = temp;
}

int numberOfOne(double a)
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

int numberOfZero(double a)
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

void displayArray(double* a, int n)
{
	for (double *i = a; i < a + n; i++)
		cout << *i << "     ";
}

void displayBinaryNumber(double* a, int n)
{
	for (double *i = a; i < a + n; i++)
		cout << bitset<8>(*i) << "     ";
	cout << "-Binary view of Initial array";
}

void displayNumberOfOne(double* a, int n)
{
	for (double *i = a; i < a + n; i++)
		cout << numberOfOne(*i) << "     ";
	cout << "   -Number of 1 in the array elements";
}

void displayNumberOfZero(double* a, int n)
{
	for (double *i = a; i < a + n; i++)
		cout << numberOfZero(*i) << "     ";
	cout << "   -Number of 0 in the array elements";
}

void isDataValidSize(int &n)
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

void isDataValidNumber(int &t)
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

void TheSameElements(int* c, int n, int &m)
{
	int k = 0;
	for (int* p = c, j = 0; p < c + n; p++)
	{
		if (*p == *(p + 1) || *p == *(p - 1))

			*p = *(p + 1);
		j++;
	}
	m = k;
}