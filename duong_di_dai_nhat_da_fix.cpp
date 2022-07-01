#include<iostream>
#include<stdbool.h>
using namespace std;
int n, m;
int a[25][25];
int Max;
int d;
void nhap()
{
	cin >> n >> m;
	for(int i= 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			a[i][j] = 0;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		x++;
		y++;
		a[x][y] = a[y][x] = 1;
	}
	d = Max = 0;
}
bool kiem_tra(int i)
{
	for(int j = 1; j <= n; j++)
	{
		if(a[i][j] == 1)
		{
			return false;
		}
	}
	return true;
}
void xuly(int i)
{
	for(int j = 1; j <= n; j++)
	{
		if(a[i][j] == 1)
		{
			a[i][j] = a[j][i] = 0;
			d++;
			if(kiem_tra(j) == true)
			{
				if(d > Max)
				{
					Max = d;
				}
			}
			else
			{
				xuly(j);
			}
			a[i][j] = a[j][i] = 1;
			d--;
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
		for(int i = 1; i <= n; i++)
		{
			xuly(i);
		}
		cout << Max << endl;
	}
	return 0;
}
