#include<iostream>
#include<set>
#include<bitset>
using namespace std;
int n, s;
int a[250];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> s;
        multiset<int>x;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i] <= s)
            {
                x.insert(a[i]);
            }
        }
        bitset <40005> b; 
        b[0] = 1;
        for(multiset<int>::iterator i = x.begin(); i != x.end(); i++)
        {
            for(int j = s; j >= *i; j--)
            {
                if(b[j - *i])
                {
                    b[j] = 1;
                }
            }
        }
        if(b[s]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}