#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int xet[1005];
vector<vector<int> >list;
void DFS(int u)
{
    xet[u] = 1;
    cout << u << " ";
    for(int i = 0; i < list[u].size(); i++)
    {
        if(!xet[list[u][i]]) DFS(list[u][i]);
    }
}
void BFS(int u)
{
    queue<int>q=queue<int>();
    q.push(u);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        if(!xet[v])
        {
            cout << v << " ";
            xet[v] = 1;
            for(int i = 0; i < list[v].size(); i++)
            {
                if(!xet[list[v][i]]) q.push(list[v][i]);
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
        int n, m, p;
        cin >> n >> m >> p;
        vector<int>v=vector<int>();
        for(int i = 0; i <= n; i++)
        {
            list.push_back(v);
        }
        for(int i = 0; i < m; i++)
        {
            int u , v;
            cin >> u >> v;
            list[u].push_back(v);
        }
        for(int i = 1; i <= n; i++)
        {
            sort(list[i].begin(), list[i].end());
            xet[i] = 0;
        }
        //DFS(p);
        BFS(p);
        list.clear();
        cout << endl;
    }
    return 0;
}