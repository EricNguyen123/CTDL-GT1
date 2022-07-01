#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
vector<int> a[1005];
int clr[1005] = {};
bitset<1005> visited;
bool check;
int n, m;

inline void DFS(int u)
{
    visited[u] = 1;
    if(!check)
        return;
    for(int j = 0; j < a[u].size(); j++)
    {
        int i = a[u][j];
        if(!visited[i])
        {
            if(!clr[i])
                clr[i] = 1 - clr[u];
            DFS(i);
        }
        else if(clr[u] == clr[i])
        {
            check = 0;
            return;
        }
    }
}

int main()
{
    int t = 1, x, y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        while(m--)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        check = 1;
        for(int i = 1; i <= n; ++i)
        {
            visited.reset();
            DFS(i);
            if(!check)
                goto End;
        }
        End:
        if(check)
            cout << "YES\n";
        else
            cout << "NO\n";
        for(int i = 1; i <= n; ++i)
        {
            a[i].clear();
            clr[i] = 0;
        }
    }
    return 0;
}
