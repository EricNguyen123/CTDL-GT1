#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int *x = new int[n];
		for(int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		int **y = new int*[n];
		for(int i = 0; i < n; i++)
		{
			y[i] = new int[n];
		}
		int d = n;
		
		while(d--)
		{
			for(int i = 0; i <= d; i++)
			{
				y[d][i] = x[i];
			}
			
			for(int i = 1; i <= d; i++)
			{
				x[i - 1] = x[i - 1] + x[i]; 
			}
		}
		int m = 0;
		while(m < n)
		{
			cout << "[";
			for(int i = 0; i <= m; i++)
			{
				cout << y[m][i]; 
				if(i < m)
				{
					cout << " ";
				}
			}
			
			cout << "] ";
			m++;
		}
		cout << endl;
	}
	return 0;
}
