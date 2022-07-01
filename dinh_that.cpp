#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int> >list(105);
int xet[105];
int BFS(int x, int u, int v)
{
    xet[u] = 1;
    queue<int>q;
    q.push(u);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i = 0; i < list[u].size(); i++)
        {
            if(xet[list[u][i]] == 0)
            {
                if(list[u][i] == v) return 0;
                q.push(list[u][i]);
                xet[list[u][i]] = 1;
            }
        }
    }
    return 1;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, u, v;
        cin >> n >> m >> u >> v;
        for(int i = 1; i <= n; i++)
        {
            list[i].clear();
            xet[i] = 0;
        }
        while(m--)
        {
            int a, b;
            cin >> a >> b;
            list[a].push_back(b);
        }
        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int ii = 1; ii <= n; ii++)
            {
                xet[ii] = 0;
            }
            xet[i] = 1;
            res += BFS(i, u, v);
        }
        cout << res - 1 << endl;
    }
    return 0;
}