#include<iostream>
#include<stdbool.h>
using namespace std;
int n, k;
int a[50];
int x[50];
void nhap()
{
	cin >> n >> k;
	a[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		int x0;
		cin >> x0;
		a[i] = a[i - 1] + x0;
	}
	x[0] = 0;
}
bool check()
{
			int s = 0;
			int th1 = 0;
			for(int l = 1; l < k; l++)
			{
				s += x[l];
				if(x[l] != x[l + 1])
				{
					th1 = 1;
					break;
				}
			}
			if(th1 == 0 && s + x[k] == a[n])
			{
				return true;
			}
			return false;
}
int d = 0;
void xu_ly(int j, int begin)
{
	for(int i = begin; i <= n; i++)
	{
		x[j] = a[i] - a[begin - 1];
		if(j == k && i == n)
		{
			if(check() == true)
			{
				d++;
			}
		}
		else 
		{
			xu_ly(j + 1, i + 1);
		}
	}
}
int main()
{
	nhap();
	xu_ly(1, 1);
	cout << d << endl;
	return 0;
}
