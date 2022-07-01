#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //cout << n;
    long long Max = -1;
    for(int i = 0; i < n; i++)
    {
        Max = max(Max, a[i]);
    }
    int l = 0, r = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == Max)
        {
            r++;
        }
        else{
            l = max(l, r);
            r = 0;
        }

    }
    cout << max(l, r) << endl;
    return 0;
}