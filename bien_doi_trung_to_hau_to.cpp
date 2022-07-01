#include<iostream>
#include<stack>
using namespace std;
int degree(char c)
{
    if(c == '^') return 5;
    if(c == '*' || c == '/') return 4;
    if(c == '+' || c == '-') return 3;
    return 2;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        string res = "";
        stack<char> st;
        for(int i = 0; i < s.length(); i++)
        {
            if(isalpha(s[i])) res += s[i];
            else if(s[i] == '(') st.push(s[i]);
            else if(s[i] == ')')
            {
                while(st.size() && st.top() != '(')
                {
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
            {
                while(st.size() && degree(st.top()) >= degree(s[i]))
                {
                    res += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(st.size())
        {
            if(st.top() != '(') res += st.top();
            st.pop();
        }
        cout << res << endl;
    }
    return 0;
}