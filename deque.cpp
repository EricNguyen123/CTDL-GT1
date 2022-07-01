#include<iostream>
#include<deque>
using namespace std;
int main()
{
    int n;
    cin >> n;
    deque<int>v=deque<int>();
    while(n--)
    {
        string s;
        cin >> s;
        int m;
        if(s == "PUSHFRONT") 
        {
            cin >> m;
            v.push_front(m);
        }
        else if(s == "PUSHBACK")
        {
            cin >> m;
            v.push_back(m);
        }
        else if(s == "POPFRONT")
        {
            if(!v.empty()) v.pop_front();
        }
        else if(s == "POPBACK")
        {
            if(!v.empty()) v.pop_back();
        }
        else if(s == "PRINTFRONT")
        {
            if(v.empty()) cout << "NONE" << endl;
            else cout << v.front() << endl;
        }
        else if(s == "PRINTBACK") 
        {
            if(v.empty()) cout << "NONE" << endl;
            else cout << v.back() << endl;
        }
    }
}