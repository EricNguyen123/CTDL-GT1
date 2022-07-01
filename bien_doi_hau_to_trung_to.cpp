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
        stack<string>st=stack<string>();
        for(int i = 0; i < s.size(); i++)
        {
            string tg = "";
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                tg = s[i] + st.top() + ')';
                st.pop();
                tg = '(' + st.top() + tg;
                st.pop();
                st.push(tg);
            }
            else{
                st.push(tg + s[i]);
            }
        }
        while(!st.empty())
        {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
    return 0;
}