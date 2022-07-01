#include<iostream>
#include<stdbool.h>
using namespace std;
long n, s, a[40], m = 0;
int MIN = 1000;
bool y[40];
long sum = 0;
int d = 0;
void xu_ly(int i)
{
	for(int j = m; j < n; j++)
	{
		if(y[j] == false)
		{
			sum += a[j];
			y[j] = true;
			if(sum == s)
			{
				if(MIN > i)
				{
					MIN = i;
					d = 1;
				}
			}
			else if(sum < s)
			{
				m = j + 1;
				xu_ly(i + 1);
			}
			sum -= a[j];
			y[j] = false;
		}
	}
}
int main()
{
	cin >> n >> s;
	for(int i = 0; i < n; i++)
	{
		y[i] = false;
		cin >> a[i];
	}
	xu_ly(1);
	if(d == 0)
	{
		cout << -1;
	}
	else
	{
		cout << MIN;
	}
	
	
	return 0;
}
