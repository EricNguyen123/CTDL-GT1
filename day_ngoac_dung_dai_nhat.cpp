#include<iostream>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        stack<int>v = stack<int>();
        v.push(-1);
        int Max = INT_MIN;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(') v.push(i);
            else{
                v.pop();
                if(!v.empty())
                {
                    Max = max(Max, i - v.top());
                }
                else{
                    v.push(i);
                }
            }
        }
        cout << Max << endl;
    }
    return 0;
}