#include<iostream>
using namespace std;
long long xuly(int dau, int cuoi)
{
    if(dau == cuoi) return dau;
    if(dau == cuoi - 1) return dau * cuoi;
    int mid = (dau + cuoi) / 2;
    return xuly(dau, mid) * xuly(mid + 1, cuoi);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        long long b[n + 1][m + 1];
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                b[i][j] = 1;
            }
        }
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                b[i][j] = b[i + 1][j] + b[i][j + 1];
            }
        }
        cout << b[0][0] << endl;
    }
    return 0;
}