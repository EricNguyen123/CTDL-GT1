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
        int n, v;
        cin >> n >> v;
        int a[n + 1], c[n + 1];
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> c[i];
        int b[n + 1][v + 1];
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= v; j++)
            {
                b[i][j] = 0;
            }
        }
        int Max = INT_MIN;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= v; j++)
            {
                if(j < a[i]) b[i][j] = b[i - 1][j];
                else b[i][j] = max(b[i - 1][j - a[i]] + c[i], b[i - 1][j]);
                Max = max(Max, b[i][j]);
            }
        }
        cout << Max << endl;
    }
    return 0;
}