#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int>res(30000,0);
        queue<int>q=queue<int>();
        q.push(n);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            if(x == m) break;
            if(x * 2 < m * 2 && !res[x * 2])
            {
                res[x * 2] = res[x] + 1;
                q.push(x * 2);
            }
            if(!res[x - 1])
            {
                res[x - 1] = res[x] + 1;
                q.push(x - 1);
            }
        }
        cout << res[m] << endl;
    }
    return 0;
}