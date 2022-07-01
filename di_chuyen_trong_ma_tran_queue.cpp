#include<iostream>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m,n;
        cin >> m >> n;
        int a[m + 1][n + 1];
        int b[m + 1][n + 1];
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                b[i][j] = m + n + 5;
            }
        }
        b[1][1] = 0;
        for(int v = 1; v <= m; v++)
        {
            for(int u = 1; u <= n; u++)
            {
                if(b[v][u] != m + n + 5)
                {
                    if(u + a[v][u] <= n) 
                    {
                        b[v][u + a[v][u]] = min(b[v][u + a[v][u]], b[v][u] + 1);
                    }
                    if(v + a[v][u] <= m) 
                    {
                        b[v + a[v][u]][u] = min(b[v + a[v][u]][u], b[v][u] + 1);
                    }
                }
            }
        }
        if(b[m][n] != m + n + 5) cout << b[m][n] << endl;
        else cout << -1 << endl;
    }
    return 0;
}