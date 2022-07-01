#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int Min = min(k, n - k);
        int a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        long long s = 0;
        for(int i = 0; i < n; i++)
        {
            if(i < Min)
            {
                s -= a[i];
            }
            else{
                s += a[i];
            }
        }
        cout << s << endl;
    }
}