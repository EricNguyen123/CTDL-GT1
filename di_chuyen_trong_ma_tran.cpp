#include<iostream>
#include<set>
using namespace std;
int n;
int m;
int a[105][105];
int x[250];
int d;
void nhap()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			a[i][j] = 1;
		}
	}
	d = 0;
}
void kiem_duyet()
{
	int i = 1;
	int j = 1;
	int f = m + n - 2;
	int g = 0;
	if(a[i][j] == 1)
	{
		for(int l = 1; l <= f; l++)
		{
			if(x[l] == 0)
			{
				if(i < n && a[i + 1][j] == 1)
				{
					i++;
					g = 0;
				}
				else
				{
					g = 1;
				}
			}
			else
			{
				if(j < m && a[i][j + 1] == 1)
				{
					j++;
					g = 0;
				}
				else
				{
					g = 1;
				}
			}
			if(g == 1)
			{
				break;
			}
		}
	}
	else
	{
		g = 1;
	}
	if(g == 0)
	{
		d++;
	}
}
void ql_nhi_phan(int i)
{
	for(int j = 0; j <= 1; j++)
	{
		x[i] = j;
		if(i == m + n - 2)
		{
			kiem_duyet();
		}
		else
		{
			ql_nhi_phan(i + 1);
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		nhap();
		ql_nhi_phan(1);
		cout << d << endl;
	}
	return 0;
}
