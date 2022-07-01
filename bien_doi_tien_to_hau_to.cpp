#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        stack<string>v = stack<string>();
        for(int i = s.size() - 1; i >= 0; i--)
        {
            string tg = "";
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') 
            {
                tg += v.top();
                v.pop();
                tg += v.top() + s[i];
                v.pop();
                v.push(tg);
            }
            else 
            {
                v.push(tg + s[i]);
            }
        }
        while(!v.empty())
        {
            cout << v.top();
            v.pop();
        }
        cout << endl;
    }
    return 0;
}