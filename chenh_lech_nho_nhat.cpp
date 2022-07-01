#include<iostream>
#include<set>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		multiset <long> s;
		for(int i = 0; i < n; i++)
		{
			long x;
			cin >> x;
			s.insert(x);
		}
		long min = 1000000000;
		for(multiset <long> ::iterator i = s.begin(); i != s.end(); i++)
		{
			if(s.count(*i) > 1)
			{
				min = 0;
			}
			else
			{
				multiset <long> ::iterator it = s.upper_bound(*i);
				if(min > *it - *i && it != s.end())
				{
					min = *it - *i;
				}
			}		
		}
		cout << min << endl;
	}
	return 0;
}
