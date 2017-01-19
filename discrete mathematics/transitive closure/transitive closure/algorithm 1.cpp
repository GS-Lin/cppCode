#include<iostream>
#include<cstring>
using namespace std;
void arrayCopy(int a[100][100], int b[100][100], int n);
void matrixPos(int a[100][100], int b[100][100],int c[100][100],int n,int m)
{
	for (int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			if (a[i][j]==1)
				for (int k = 0; k < n; k++)
				{
					if (b[j][k] == 1)
						c[i][k] = 1;
				}
		}
}
void transitiveClosure(int a[100][100],int c[100][100], int n)
{
	int A[100][100];
	int temp[100][100];
	arrayCopy(A, a, n);
	arrayCopy(c, a, n);
	for (int i = 2; i <= n; i++)
	{
		arrayCopy(temp, A, n);
		matrixPos(temp, temp, A, n, n);
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (c[j][k] == 1 || A[j][k] == 1)
					c[j][k] = 1;
	}
}
void arrayCopy(int a[100][100], int b[100][100], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = b[i][j];
}
void warshall(int a[100][100], int w[100][100], int n)
{
	arrayCopy(w, a, n);
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				if (w[i][j] == 1 || (w[i][k] == 1 && w[k][j] == 1))
					w[i][j] = 1;
		}
	}
}
void main()
{
	int a[100][100] = { 0 };
	int c[100][100] = { 0 };
	int n;
	n = 5;
	a[0][2] = 1; a[1][3] = 1; a[2][0] = 1; a[2][4] = 1; a[3][2] = 1;
	a[4][0] = 1; a[4][1] = 1; a[4][3] = 1;
	warshall(a, c, n);
	for (int j = 0; j < n; j++)
	{
		for (int k = 0; k < n; k++)
			cout << c[j][k] << ends;
		cout << endl;
	}
	system("pause");
}