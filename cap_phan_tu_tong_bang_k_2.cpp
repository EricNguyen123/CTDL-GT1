#include<iostream>
#include<map>
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
		map <long, long> a;
		long *x = new long[n];
		for(int i = 0; i < n; i++)
		{
			cin >> x[i];
			a[x[i]]++;
		}
		long d = 0;
		for(int i = 0; i < n; i++)
		{
			if(x[i] == k - x[i])
			{
				d += (a[x[i]] - 1);
			}
			else
			{
				d += a[k - x[i]];
			}
		}
		cout << d / 2 << endl;
	}
	return 0;
}
