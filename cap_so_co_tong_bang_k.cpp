#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		int k;
		cin >> n;
		cin >> k;
		int *a = new int[n];
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int d = 0;
		for(int i = 0; i < n; i++)
		{
			int kt = k - a[i];
			for(int j = 0; j < n; j++)
			{
				if(a[j] == kt && j != i)
				{
				
					d++;
				}
			}
		}
		cout << d / 2 << endl;
	}
	return 0;
}

