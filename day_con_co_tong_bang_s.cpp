#include<iostream>
#include<stdbool.h>
#include<algorithm>
#define e 1000000007
using namespace std;
long d = 0;
long Min = e;
void xu_ly(long i, long long a[], long long x[], long long &s, long n, long long k, long m)
{
	for(long j = m ; j < n; j++)
	{
			s += a[j];
			d++;
			x[i] = a[j];
		    if(s == k && d < Min)
		    {
		    	Min = d;
			}
			else if(s < k && d < Min)
			{
				xu_ly(i + 1, a, x, s, n, k, j + 1);
			}
			s -= a[j];
			d--;
		
		
	}
}
int main()
{
		long long n, k;
		cin >> n >> k;
		 long long *a = new long long[n];
		long long *x = new long long[n];
		for(long i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		long long s = 0;
		d = 0;
		xu_ly(0, a, x, s, n, k, 0);
		if(Min < 35)
		{
			cout << Min << endl;
		}
		else{
			cout << - 1 << endl;
		}
		
		
	return 0;
}