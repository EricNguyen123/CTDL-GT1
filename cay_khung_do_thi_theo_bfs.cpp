#include<iostream>
#include<vector>
#include<bitset>
#include<queue>
using namespace std;
int n, m, U, sc;
vector<vector<int> > list(1005);
//bitset<1005>xet;
int xet[1005];
int CBT[1005][2];
void TreeBFS(int v)
{
    xet[v] = 1;
    queue<int>q=queue<int>();
    q.push(v);
    while(!q.empty())
    {
        v = q.front();
        q.pop();
        for(int i = 0; i < list[v].size(); i++)
        {
            if(xet[list[v][i]] == 0)
            {
                sc++;
                xet[list[v][i]] = 1;
                CBT[sc][0] = v;
                CBT[sc][1] = list[v][i];
                q.push(list[v][i]);
                if(sc == n - 1) return;
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
        cin >> n >> m >> U;
        for(int i = 1; i <= n; i++) 
        {
            list[i].clear();
            xet[i] = 0;
        }
        for(int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            list[u].push_back(v);
            list[v].push_back(u);
        }
        sc = 0;
        TreeBFS(U);
        if(sc < n - 1) cout << -1 << endl;
        else{
            for(int i = 1; i <= sc; i++)
            {
                cout << CBT[i][0] << " " << CBT[i][1] << endl;
            }
        }
    }
    return 0;
}