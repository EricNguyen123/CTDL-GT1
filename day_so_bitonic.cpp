#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        long long a[n],b[n],c[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = c[i] = a[i];
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(a[j] < a[i])
                {
                    b[i] = max(b[i], b[j] + a[i]);
                }
            }
        }
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = n - 1; j > i; j--)
            {
                if(a[j] < a[i])
                {
                    c[i] = max(c[i], c[j] + a[i]);
                }
            }
        }
        long long Max = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            Max = max(Max, b[i] + c[i] - a[i]);
        }
        cout << Max << endl;
    }
    return 0;
}