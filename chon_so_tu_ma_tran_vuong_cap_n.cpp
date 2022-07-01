#include<iostream>
#include<vector>
#include<stdbool.h>
using namespace std;
int n, k;
int a[11][11];
bool check[11];
vector <int> x(11);
vector <vector <int> > v;
void nhap()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		check[i] = false;
		for(int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	
}
bool kiem_tra()
{
	int s = 0;
	for(int i = 0; i < n; i++)
	{
		s += a[i][x[i]];
	}
	if(s == k)
	{
		return true;
	}
	return false;
}
void xu_ly(int i)
{
	for(int j = 0; j < n; j++)
	{
		if(check[j] == false)
		{
			x[i] = j;
			check[j] = true;
			if(i == n - 1)
			{
				if(kiem_tra() == true)
				{
					v.push_back(x);
				}
			}
			else
			{
				xu_ly(i + 1);
			}
			check[j] = false;
		}
	}
}
void in()
{
	cout << v.size() << endl;
	for(int i = 0; i < v.size(); i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << v[i][j] + 1 << " ";
		}
		cout << endl;
	}
	
}
int main()
{
	nhap();
	xu_ly(0);
	in();
	return 0;
}
