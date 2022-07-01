#include<iostream>
#include<vector>
#include<bitset>
#include<stack>
#include<algorithm>
using namespace std;
int n, m;
bitset<1005>xet;
vector<vector<int> >list(1005);
int truoc[1005];
int check;
int en;
void DFS(int u)
{
    if(check == 1) return;
    xet[u] = 1;
    for(int i = 0; i < list[u].size(); i++)
    {
        if(!xet[list[u][i]])
        {
            truoc[list[u][i]] = u;
            DFS(list[u][i]);
        }
        else{
            if(list[u][i] != truoc[u] && list[u][i] == 1)
            {
                check = 1;
                en = u;
                return;
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
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
        {
            list[i].clear();
            xet[i] = 0;
            truoc[i] = 0;
        }
        while(m--)
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
        check = 0;
        DFS(1);
        if(check == 0) cout << "NO" << endl;
        else{
            stack<int>st = stack<int>();
            int j = en;
            while(truoc[j] != 0)
            {
                st.push(j);
                j = truoc[j];
            }
            cout << 1 << " ";
            while(!st.empty())
            {
                cout << st.top() << " ";
                st.pop();
            }
            cout << 1;
            cout << endl;
        }
        xet.reset();
    }
    return 0;
}