#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        stack<char>st = stack<char>();
        string s;
        cin >> s;
        int d = 0;
        for(int i = 0; i < s.size();i++)
        {
            if(st.empty()) st.push(s[i]);
            else if(s[i] == ')' && st.top() == '(')
            {
                st.pop();
            }
            else if(st.top() == ')' && s[i] == '(')
            {
                st.push(s[i]);
            }
            else if(s[i] == ')' && st.top() == ')')
            {
                st.push(s[i]);
            }
            else if(s[i] == '(' && st.top() == '(')
            {
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            char a[2];
            a[0] = st.top();
            st.pop();
            a[1] = st.top();
            st.pop();
            if(a[0] == '(' && a[1] == ')') d += 2;
            else if(a[0] == '(' && a[1] == '(') d++;
            else if(a[0] == ')' && a[1] == ')') d++;
        }
        cout << d << endl;
    }

    return 0;
}