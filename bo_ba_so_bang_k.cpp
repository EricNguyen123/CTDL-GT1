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
		long k;
		cin >> n;
		cin >> k;
		long *x = new long[n];
		for(int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		sort(x, x + n);
		long a, b, c;
		int d = 0;
		for(int i = 0; i < n; i++)
		{
			a = x[i];
			int l = n - 1;
			int r = i + 1;
			while(r < l)
			{
				b = x[l];
				c = k - x[r];
				long s = c - b;
				if(a == s)
				{
					cout << "YES" << endl;
					d = 1;
					break;
				}
				else if(a < s)
				{
					r++;
					
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
