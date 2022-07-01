#include<iostream>
#include<algorithm>
#include<stdbool.h>
using namespace std;

bool check(string aa, string bb)
{
	return aa < bb;
}
void xet(string *s, int k, string *b, long &o, int *x)
{
	string *a = new string[k];
	for(int i = 1; i <= k; i++)
	{
		a[i - 1] = s[x[i] - 1];
	}
	sort(a, a + k, check);
	for(int i = 0; i < k; i++)
	{
		b[o] += a[i];
		b[o] += " ";
	}
	o++;
}
void xuly(int i, string *s, int n, int k, string *b, long &o, int *x)
{
	for(int j = x[i - 1] + 1; j <= n - k + i; j++)
	{
		x[i] = j;
		if(i == k)
		{
			xet(s, k, b, o, x);
		}
		else
		{
			xuly(i + 1, s, n, k, b, o, x);
		}
	}
}
int main()
{
    int n;
    int k;
    int x[100];
    string b[1000000] = {""};
    long o = 0;
	x[0] = 0;
	cin >> n;
	cin >> k;
	string *s = new string[n];
	int j = 0;
	for(int i = 0; i < n; i++)
	{
		string y;
		cin >> y;
		int d = 0;
		for(int l = 0; l < j; l++)
		{
			if(y == s[l])
			{
				d = 1;
				break;
			}
			
		}
		if(d == 0)
		{
			s[j] = y;
			j++;
		}
	}
	n = j;
	
	xuly(1, s, n, k, b, o, x);
	
	sort(b, b + o, check);
	for(int i = 0; i < o; i++)
	{
		cout << b[i] << endl;
	}
	return 0;
}
