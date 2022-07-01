#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin, s);
        stack<string>x = stack<string>();
        int i = 0;
        while(i < s.size())
        {
            while(s[i] == ' ' && i < s.size()) 
            {
                i++;
            }
            string a = "";
            while(s[i] != ' ' && i < s.size())
            {
                a = a + s[i];
                i++;
            }
            x.push(a);
        }
        while(!x.empty())
        {
            cout << x.top() << " ";
            x.pop();
        }
        cout << endl;
    }
    return 0;
}