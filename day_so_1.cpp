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
		int d = n;
		while(d--)
		{
			cout << "[";
			for(int i = 0; i <= d; i++)
			{
				cout << x[i]; 
				if(i < d)
				{
					cout << " ";
				}
			}
			cout << "]" << endl;
			for(int i = 1; i <= d; i++)
			{
				x[i - 1] = x[i - 1] + x[i]; 
			}
		}
	}
	return 0;
}
