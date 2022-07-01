#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		int k;
		cin >> n >> k;
		vector <int> a;
		for(int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			a.push_back(x);
		}
		sort(a.begin(), a.end());
		long long d = 0;
		for(int i = 0; i < n; i++)
		{
			vector <int> ::iterator x = upper_bound(a.begin(), a.end(), a[i] + k - 1);
			if(x != a.end())
			{
				x--;
		        d += int(x - a.begin()) - i;
			}
			else
			{
				d += n - 1 - i;
			}
		}
		cout << d << endl;
	}
	return 0;
}
