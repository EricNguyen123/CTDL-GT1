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
        stack<char>a=stack<char>();
        stack<char>b=stack<char>();
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != ')')
            {
                a.push(s[i]);
            }
            else{
                while(!a.empty() && a.top() != '(')
                {
                    b.push(a.top());
                    a.pop();
                }
                a.pop();
                if(!a.empty() && a.top() == '-')
                {
                    while(!b.empty())
                    {
                        if(b.top() == '+')
                        {
                            a.push('-');
                            b.pop();
                        }
                        else if(b.top() == '-')
                        {
                            a.push('+');
                            b.pop();
                        }
                        else{
                            a.push(b.top());
                            b.pop();
                        }
                    }
                }
                else{
                    while(!b.empty())
                    {
                        a.push(b.top());
                        b.pop();
                    }
                }
            }
        }
        stack<char>res=stack<char>();
        while(!a.empty())
        {
            res.push(a.top());
            a.pop();
        }
        while(!res.empty())
        {
            cout << res.top();
            res.pop();
        }
        cout << endl;
    }
    return 0;
}