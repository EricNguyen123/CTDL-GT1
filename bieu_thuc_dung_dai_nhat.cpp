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
        stack<char>st=stack<char>();
        int d = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                st.push(s[i]);
            }
            else if(s[i] == ')')
            {
                if(!st.empty())
                {
                    d += 2;
                    st.pop();
                }
            }
        }
        cout << d << endl;
    }
    return 0;
}