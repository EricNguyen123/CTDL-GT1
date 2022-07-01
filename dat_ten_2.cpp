#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void in(int k, int x[])
{
	for(int i = 1; i <= k; i++)
	{ 
	    string s = "";
		s += char(x[i] - 1 + 'A');
		cout << s;
		
	}
	cout << endl;
}
void xu_ly(int n, int k, int x[], int i)
{
	for(int j = x[i - 1] + 1; j <= n - k + i; j++)
	{
		x[i] = j;
		if(i == k)
		{
			in(k, x);
		}
		else
		{
			xu_ly(n, k, x, i + 1);
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
		int *x = new int[k + 1];
		x[0] = 0;
		xu_ly(n, k, x, 1);
	}
	return 0;
}
