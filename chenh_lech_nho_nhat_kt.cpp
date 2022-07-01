#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int n, k;
string s[15];
int y[15];
int x[15];
int Min;
int chuyendoi(string a)
{
    int b = 0;
    for(int i = 0; i < a.size(); i++)
    {
        b = b * 10 + int(a[i] - '0');
    }
    return b;
}
string kqhoanvi(string a)
{
    string b = "";
    for(int i = 1; i <= k; i++)
    {
        b = b + a[x[i] - 1];
    }
    return b;
}
void XetDuyet()
{
    int a,b;
    a = INT_MAX;
    b = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        a = min(a, chuyendoi(kqhoanvi(s[i])));
        b = max(b, chuyendoi(kqhoanvi(s[i])));
    }
    Min = min(Min, b - a);
}
void hoanvi(int i)
{
    for(int j = 1; j <= k; j++)
    {
        if(y[j] == 0)
        {
            y[j] = 1;
            x[i] = j;
            if(i == k)
            {
                XetDuyet();
            }
            else{
                hoanvi(i + 1);
            }
            y[j] = 0;
        }
    }
}
int main()
{
    cin >> n >> k;
    Min = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for(int i = 1; i <= k; i++)
    {
        y[i] = 0;
    }
    hoanvi(1);
    cout << Min << endl;
    return 0;
}