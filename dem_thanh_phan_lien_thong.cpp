#include<iostream>
#include<vector>
#include<stdbool.h>
#include<bitset>
#include<queue>
#include<algorithm>
using namespace std;

vector<vector<int> >list(10005);
bitset<10005>xet;
void BFS(int u)
{
    queue<int>q=queue<int>();
    q.push(u);
    xet[u] = 1;
    while(q.size())
    {
        int v = q.front();
        q.pop();
        for(int i = 0; i < list[v].size(); i++)
        {
            if(!xet[list[v][i]])
            {
                q.push(list[v][i]);
                xet[list[v][i]] = 1;
            }
        }
    }
}
int main()
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int u, v;
        for(int i = 1; i <= n; i++) {
            xet[i] = 0;
            list[i].clear();
        }
        for(int i = 1; i <= m; i++)
        {
            cin >> u >> v;
            list[u].push_back(v);
            list[v].push_back(u);
        }
        
        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!xet[i])
            {
                BFS(i);
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}