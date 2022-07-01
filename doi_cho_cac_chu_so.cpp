#include<iostream>
using namespace std;
int k;
string s;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> k;
		cin >> s;
		for(int  i = 0; i <s.size(); i++)
		{
			char Max = s[s.size() - 1];
			int vt = s.size() - 1;
			for(int j = s.size() - 1; j > i && k > 0; j--)
			{
				if(Max < s[j])
				{
					Max = s[j];
					vt = j;
				}
			}
			if(Max > s[i] && k > 0)
			{
				char tg = s[i];
				s[i] = s[vt];
				s[vt] = tg;
				k--;
			}
		}
		cout << s << endl;
	}
	return 0;
}
