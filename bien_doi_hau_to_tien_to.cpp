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
        for(int i = 0; i < s.size(); i++)
        {
            string a = "";
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                string b = "";
                b = b + v.top();
                v.pop();
                b = v.top() + b;
                v.pop();
                b = s[i] + b;
                v.push(b);
            }
            else{
                v.push(a + s[i]);
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