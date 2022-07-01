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
        int n, k;
        cin >> n >> k;
        int a[n + 5];
        for(int i = 0; i < n; i++)
        { 
            cin >> a[i];
            a[i] %= k;
        }
        int d[n][k];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < k; j++)
            {
                d[i][j] = INT_MIN;
            }
              
        }
            
        d[0][a[0]] = 1;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < k; j++)
            {
                d[i][j] = max(d[i - 1][j], d[i - 1][(j + k - a[i]) % k] + 1);
            }
                
        }
            
        cout << d[n - 1][0] << endl;
    }
    return 0;
}