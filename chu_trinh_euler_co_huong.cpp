#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> >list;
vector<vector<int> >list1;
int KiemTraEuler_Cycle(int n)
{
    int d = 0;
    for(int i = 1; i <=n; i++)
    {
        if(list[i].size() != list1[i].size()) return 0;
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        list.resize(n + 1);
        list1.resize(n + 1);
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            list[u].push_back(v);
            list1[v].push_back(u);
        }
        if(KiemTraEuler_Cycle(n) == 1)
        {
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        list.clear();
        list1.clear();
    }
    return 0;
}