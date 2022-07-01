#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<climits>
using namespace std;
int n, m;
int list[1006][1006];
int xet[1006];
int Max = INT_MIN;
int res = 0;
int x;
void Reinit(int n)
{
    for(int i = 1; i <= n; i++)
    {
        xet[i] = 0;
    }
    res = 0;
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
void Duyetdinhtru()
{
    for(int i = 1; i <= n; i++)
	{
		if(!xet[i])
        {
            res++;
            DFS(i);
        }
	}
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        Max = 1;
        int kq = 0;
        Input();
        for(int i = 1; i <= n; i++)
        {
            Reinit(n);
            xet[i] = 1;
            Duyetdinhtru();
            if(Max < res)
            {
                Max = res;
                kq = i;
            }
        }
        cout << kq;
        cout << endl;
    }
    return 0;
}