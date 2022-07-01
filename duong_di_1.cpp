#include<iostream>
using namespace std;
int d = 0;
void in(int n, string *x)
{
	for(int i = 1; i <= n; i++)
	{
		cout << x[i];
	}
	cout << " ";
}
void xuly(int i, int **a, string *x, int m, int n, int l)
{
		for(int j = m; j < n; j++)
		{
			if(a[l][j] == 1)
			{
				if(j == m)
				{
					if(a[l - 1][j] == 1 && l >= 1)
					{
						x[i] = "D";
					}
					else if(l == 0)
					{
						x[i] = "D";
					}
				}
				else
				{
					if(a[l][j - 1] == 1 && j > m)
					{
						i++;
					    x[i]= "R";
					}
					
					
				}
				if(l == n - 1 && j == n - 1)
				{
					in(i, x);
					d = 1;
				}
				else if(l < n - 1 && j < n - 1)
				{
					xuly(i + 1, a, x, j, n, l + 1);
				}
			
			}
			
		}
	

}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int **a = new int*[n];
		for(int i = 0; i < n; i++)
		{
			a[i] = new int[n];
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}
		string *x = new string[2 * n];
		xuly(0, a, x, 0, n, 0);
		cout << endl;
	}
	return 0;
}
