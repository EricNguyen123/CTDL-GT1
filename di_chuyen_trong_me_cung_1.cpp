#include<iostream>
#include<set>
using namespace std;
int n;
int a[20][20];
int x[50];
int d;
void nhap()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	d = 0;
}
void kiem_duyet()
{
	int i = 1;
	int j = 1;
	int m = 2 * n - 2;
	string s = "";
	int g = 0;
	if(a[i][j] == 1)
	{
		for(int l = 1; l <= m; l++)
		{
			if(x[l] == 0)
			{
				if(i < n && a[i + 1][j] == 1)
				{
					s += "D";
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
				if(j < n && a[i][j + 1] == 1)
				{
					s += "R";
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
		cout << s << " ";
		d = 1;
	}
}
void ql_nhi_phan(int i)
{
	for(int j = 0; j <= 1; j++)
	{
		x[i] = j;
		if(i == 2 * n - 2)
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
		if(d == 0)
		{
			cout << -1;
		}
		cout << endl;
	}
	return 0;
}
