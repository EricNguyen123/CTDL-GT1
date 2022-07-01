#include<iostream>
#include<set>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n, k;
        cin >> n >> k;
        long long a[n + 5];
        for(int i = 1; i <= n; i++)
        { 
            cin >> a[i];
        }
        int d = 0;
        if(k == 0)
        {
            for(int i = 1; i <= n; i++)
            {
                if(a[i] == 0) {d = 1; break;}
            }
            if(d == 1) cout << "YES" << endl;
            else cout << "NO" << endl;
            continue;
        }
        set<long long>v;
        v.insert(0);
        long long b = 0;
        for(int i = 1; i <= n; i++)
        {
            b += a[i];
            v.insert(b);
            if(b == k) d = 1;
            else if(b > k)
            {
                long long c = b - k;
                if(v.find(c) != v.end())
                {
                    d = 1;
                    break;
                }
            }
        }
        if(d == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}