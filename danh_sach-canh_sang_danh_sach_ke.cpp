#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int> >list(n + 1);
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            list[u].push_back(v);
            list[v].push_back(u);
        }
        for(int i = 1; i <= n; i++)
        {
            cout << i << ": ";
            sort(list[i].begin(), list[i].end());
            for(int j = 0; j < list[i].size(); j++)
            {
                cout << list[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}