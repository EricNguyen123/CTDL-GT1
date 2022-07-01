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
        stack<int>st = stack<int>();
        st.push(1);
        int Max = 1;
        int d = 1;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'I')
            {
                d = 1;
                Max = Max + 1;
                st.push(Max);
            }
            else if(s[i] == 'D')
            {
                stack<int>tg;
                int c = d;
                while(c--)
                {
                    tg.push(st.top());
                    st.pop();
                }
                Max = Max + 1;
                st.push(Max);
                while(!tg.empty())
                {
                    st.push(tg.top());
                    tg.pop();
                }
                d++;
            }
        }
        stack<int>tg;
        while(!st.empty())
        {
            tg.push(st.top());
            st.pop();
        }
        while(!tg.empty())
        {
            cout << tg.top();
            tg.pop();
        }
        cout << endl;
    }
    return 0;
}