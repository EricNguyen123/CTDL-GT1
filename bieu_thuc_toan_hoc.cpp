#include<iostream>
using namespace std;
int a[7];
string s[5];
int x[7];
int y[7];
bool z[7];
int d = 0;
void khoi_tao()
{
	for(int i = 1; i <= 5; i++)
	{
		cin >> a[i];
		z[i] = false;
	}
	d = 0;
}

bool check()
{
	int sum;
	sum = a[y[1]];
	
	for(int i = 1; i <= 4; i++)
	{
		if(s[x[i]] == "*")
		{
			sum *= a[y[i + 1]];
		}
		else if(s[x[i]] == "+")
		{
			sum += a[y[i + 1]];
		}
		else if(s[x[i]] == "-")
		{
			sum -= a[y[i + 1]];
		}
	}
	if(sum == 23)
	{
		return true;
	}
	return false;
}
void xu_ly_2(int i)
{
	for(int j = 1; j <= 5; j++)
	{
		if(d == 1)
		{
			break;
		}
		if(z[j] == false)
		{
			y[i] = j;
			z[j] = true;
			if(i == 5)
			{
				
				if(check() == true)
				{
					d = 1;
				}
			}
			else
			{
				xu_ly_2(i + 1);
			}
			z[j] = false;
		}
	}
}
void xu_ly_1(int i)
{
	for(int j = 1; j <= 3; j++)
	{
		if(d == 1)
		{
		    break;
		}
		x[i] = j;
		if(i == 4)
		{
			xu_ly_2(1);
			
		}
		else
		{
			xu_ly_1(i + 1);
		}
	}
}
int main()
{
	s[1] = "+";
	s[2] = "-";
	s[3] = "*";
	int t;
	cin >> t;
	while(t--)
	{
		khoi_tao();
		xu_ly_1(1);
		if(d == 1)
		{
			cout  << "YES" << endl;
		}
		else
		{
			cout  << "NO" << endl;
		}
	}
	return 0;
}
