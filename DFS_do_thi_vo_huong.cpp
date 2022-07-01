#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<bool>xet(100000);
vector<vector<int> >list(100000);
int n, m, p;
void DFS(int u)
{
    xet[u] = true;
    cout << u << " ";
    for(int i = 0; i < list[u].size(); i++)
    {
        if(xet[list[u][i]] == false)
        {
            DFS(list[u][i]);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> p;
        for(int i = 0; i <= n; i++)
        {
            vector<int>v=vector<int>();
            list.push_back(v);
            xet.push_back(false);
        }
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            list[u].push_back(v);
            list[v].push_back(u);
        }
        for(int i = 1; i <= n; i++)
        {
            sort(list[i].begin(), list[i].end());
        }
        DFS(p);
        cout << endl;
        xet.clear();
        list.clear();
    }
    return 0;
}