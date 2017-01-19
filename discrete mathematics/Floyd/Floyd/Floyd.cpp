#include<iostream>
using namespace std;
void Floyd(int a[100][100], int d[100][100],int n)
{
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			for (int k = 0; k < n; k++)
			{
				if (d[j][i] + d[i][k] < d[j][k])
					d[j][k] = d[j][i] + d[i][k];
			}
}
void print(int d[100][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << d[i][j] << ends;
		cout << endl;
	}
}
void main()
{
	const int inf = 99999999;
	int a[100][100];
	int dist[100][100];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			dist[i][j] = inf;
		}
	for (int i = 0; i < m; i++)
	{
		int s, e, d;
		cin >> s >> e >> d;
		a[s][e] = d;
	}
	Floyd(a,dist,n);
	print(dist,n);
	system("pause");
}