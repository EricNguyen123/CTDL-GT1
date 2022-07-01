#include<iostream>
#include<queue>
using namespace std;
int check(string s, int n)
{
    unsigned long long x = 0;
    for(int i = 0; i < s.size(); i++)
    {
        x = x * 10 + int(s[i] - '0');
        x %= n;
    }
    return !x;
}
string xuly(int n)
{
	queue<string>s;
    s.push("1");
    while(!s.empty())
    {
        string a = s.front();
        s.pop();
        if(check(a, n) == 1) return a;
        s.push(a + "0");
        s.push(a + "1");
    }
    return "-1";
}
int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin >> n;
        string res = xuly(n);
        if(res != "-1") cout << res << endl;
	}
}
