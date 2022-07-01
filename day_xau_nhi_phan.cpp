#include<iostream>
#include<string>
#include<cstring>
using namespace std;

unsigned long long length[93];

void fibo()
{
	length[1] = 1;
	length[2] = 1;
	for(int i = 3; i < 93; i++)
	{
		length[i] = length[i - 1] + length[i - 2];
	}
}

string xu_ly(int n, unsigned long long k, unsigned long long length[])
{
	if(n == 1)
	{
		return "0";
	}
	if(n == 2)
	{
		return "1";
	}
	if(k > length[n - 2])
	{
		return xu_ly(n - 1, k - length[n - 2], length);
	}
	return xu_ly(n - 2, k, length);
}

int main()
{
	fibo();
	int t;
	cin >> t;
	while(t--)
	{
		unsigned long long n, k;
		cin >> n >> k;
		cout << xu_ly(n, k, length) << endl;
	   
	}
	return 0;
}
