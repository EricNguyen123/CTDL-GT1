#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = 1;
    }
    int Max = 1;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[j] < a[i])
            {
                b[i] = max(b[i], b[j] + 1);
            }
        }
        Max = max(Max, b[i]);
    }
    cout << Max << endl;
    return 0;
}