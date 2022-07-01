#include<iostream>
#include<algorithm>
#include<stdbool.h>
#include<vector>
using namespace std;
int n;
int a[20];
int x[20];
int sum;
vector<vector<int> >res;
vector<int> v;
bool check(int a, int b)
{
    return a > b; 
}
void xetduyet(int g)
{
    for(int i = 0; i <= g; i++)
    {
        sum += x[i];
    }
    if(sum % 2 == 0) return;
    for(int i = 0; i <= g; i++)
    {
        v.push_back(x[i]);
    }
    res.push_back(v);
    v.clear();
}
void xuly(int i,int m)
{
    for(int j = m; j < n; j++)
    {
        x[i] = a[j];
        sum = 0;
        xetduyet(i);
        xuly(i + 1, j + 1);
    }
}
void in()
{
    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {       
        sum = 0;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n, check);
        res.clear();
        xuly(0, 0);
        sort(res.begin(), res.end());
        in();
    }
    
    return 0;
}