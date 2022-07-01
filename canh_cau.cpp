#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int n, m;
int list[1006][1006];
int xet[1006];
void Reinit(int n)
{
    for(int i = 1; i <= n; i++)
    {
        xet[i] = 0;
    }
}
void Input()
{
    cin >> n >> m;
    Reinit(n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) list[i][j] = 0;
    }
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        list[u][v] = list[v][u] = 1;
    }
}
void DFS(int u)
{
    xet[u] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(list[u][i] == 1 && xet[i] == 0)
        {
            DFS(i);
        }
    }
}
int KiemTraLienThong()
{
    for(int i = 1; i <= n; i++)
    {
        if(xet[i] == 0) return 1;
    }
    return 0;
}
void DuyetCau()
{
    Input();
    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(list[i][j] == 1)
            {
                list[i][j] = list[j][i] = 0;
                DFS(1);
                if(KiemTraLienThong() == 1)
                {
                    cout << i << " " << j << " ";
                }
                list[i][j] = list[j][i] = 1;
                Reinit(n);
            }
           
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        DuyetCau();
        cout << endl;
    }
    return 0;
}