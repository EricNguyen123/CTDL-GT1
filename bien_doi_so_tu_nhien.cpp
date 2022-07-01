#include<iostream>
#include<queue>
#include<unordered_map>
#include<math.h>
using namespace std;
void Xuly(int n)
{
    if(n == 1)
    {
        cout << 0 << endl;
        return;
    }
    unordered_map<int, int>res;
    queue<int>q = queue<int>();
    q.push(n);
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        int m = sqrt(top);
        for(int i = 2; i <= m; i++)
        {
            if(top % i == 0 && res[top / i] == 0)
            {
                if(top / i == 1)
                {
                    cout << res[top] + 1 << endl;
                    return;
                }
                res[top / i] = res[top] + 1;
                q.push(top / i);
            }
        }
        if(top - 1 == 1) 
        {
            cout << res[top] + 1 << endl;
            return;
        }
        if(res[top - 1] == 0)
        {
            res[top - 1] = res[top] + 1;
            q.push(top - 1);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        Xuly(n);
    }
    return 0;
}