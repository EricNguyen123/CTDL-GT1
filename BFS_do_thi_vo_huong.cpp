#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, p;
        cin >> n >> m >> p;
        vector<vector<int> >list(n + 5);
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            list[u].push_back(v);
            list[v].push_back(u);
        }
        queue<int>x=queue<int>();
        x.push(p);
        int xet[n + 5];
        for(int i = 1; i <= n; i++)
        {
            sort(list[i].begin(), list[i].end());
            xet[i] = 0;
        }
        while(!x.empty())
        {
            int u = x.front();
            x.pop();
            if(xet[u] == 0)
            {
                cout << u << " ";
                xet[u] = 1;
            }
            for(int i = 0; i < list[u].size(); i++)
            {
                if(xet[list[u][i]] == 0)
                {
                    x.push(list[u][i]);
                }
            }
        }
        cout << endl;
    }
    return 0;
}