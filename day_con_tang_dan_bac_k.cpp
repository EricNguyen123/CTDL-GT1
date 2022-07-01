#include<iostream>
#include<stdbool.h>
using namespace std;
int n, k, d, x[110], a[110];
void nhap()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	d = 0;
	x[0] = 0;
}
bool kiemtra()
{
	for(int i = 1; i < k; i++)
	{
		if(a[x[i]] > a[x[i + 1]])
		{
			return false;
		}
	}
	return true;
}
void xuly(int i)
{
	for(int j = x[i - 1] + 1; j <= n - k + i; j++)
	{
		x[i] = j;
		if(i == k)
		{
			if(kiemtra() == true)
			{
				d++;
			}
		}
		else
		{
			xuly(i + 1);
		}
	}
}
int main()
{
	nhap();
	xuly(1);
	cout << d << endl;
	return 0;
}
