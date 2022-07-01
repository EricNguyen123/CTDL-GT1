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
		int n, k;
		long long s = 0;
		cin >> n >> k;
		vector <long long> a;
		for(int i = 0; i < n; i++)
		{
			long long x;
			cin >> x;
			a.push_back(x);
		}
		sort(a.begin(), a.end());
		for(int i = 0; i < n; i++)
		{
			for(int j = i + 1; j < n; j++)
			{
				int x = lower_bound(a.begin() + j + 1, a.end(), k -a[i] - a[j]) - a.begin();
				s += x - j - 1;
				
				
			}
		}
		cout << s << endl;
	}
}
