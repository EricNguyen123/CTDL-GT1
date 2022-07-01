#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		long long *x = new long long[n];
		for(int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		sort(x, x + n);
		for(int i = 0; i < n; i++)
		{
			x[i] = (x[i] * x[i]);
		}
		long long a, b, c, d = 0;
		for(int i = 0; i < n; i++)
		{
			a = x[i];
			int l = n - 2;
			int r = n - 1;
			while(l > i)
			{
				b = x[l];
				c = x[r];
				long long s = c - b;
				if(s == a)
				{
					cout << "YES" << endl;
					d = 1;
					break;
				} 
				else if(a < s)
				{
					r--;
				}
				else
				{
					l--;
				}
			}
			if(d == 1)
			{
				break;
			}
		}
		if(d == 0)
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
