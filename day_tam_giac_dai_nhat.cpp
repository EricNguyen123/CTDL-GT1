#include<iostream>
using namespace std;
int n;
int a[100005];
int l[100005];
int r[100005];

void nhap()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		l[i] = 0;
		r[i] = 0;
	}
	
}
void xuly()
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] >= a[i - 1] && i > 0)
		{
			l[i] = l[i - 1] + 1;
		}
		else
		{
			l[i] = 1;
		}
		
	}
	for(int i = n - 1; i >= 0; i--)
	{
		if(a[i] >= a[i + 1] && i < n - 1)
		{
			r[i] = r[i + 1] + 1;
		}
		else
		{
			r[i] = 1;
		}
	}
	int max = 0;
	for(int i = 0; i < n; i++)
	{
		int x = l[i] + r[i] - 1;
		if(x > max)
		{
			max = x;
		}
	}
	cout << max << endl;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		nhap();
		xuly();
	}
	return 0;
}
