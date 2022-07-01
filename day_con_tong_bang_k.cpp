#include<iostream>
#include<stdbool.h>
#include<algorithm>
using namespace std;
int d = 0;
void in(int x[], int n)
{
	cout << "[";
	for(int i = 0; i <= n; i++)
	{
		cout << x[i];
		if(i < n){
			cout << " ";
		} 
	}
	cout << "] ";
}
void xu_ly(int i, int a[], int x[], bool b[], long &s, int n, int k, int m)
{
	for(int j = m ; j < n; j++)
	{
		if(b[j] == true)
		{
			s += a[j];
			x[i] = a[j];
			b[j] = false;
		    if(s == k)
		    {
		    	d = 1;
		    	in(x, i);
			}
			else if(s < k)
			{
				xu_ly(i + 1, a, x, b, s, n, k, j + 1);
			}
			s -= a[j];
			b[j] = true;
		}
		
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		int *a = new int[n];
		int *x = new int[n];
		bool *b = new bool[n];
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			b[i] = true;
		}
		sort(a, a + n);
		long s = 0;
		d = 0;
		xu_ly(0, a, x, b, s, n, k, 0);
		if(d == 0)
		{
			cout << -1 << endl;
		}
		cout << endl;
	}
	return 0;
}
