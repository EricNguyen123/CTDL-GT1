#include<iostream>
#include<algorithm>
#include<stdbool.h>
using namespace std;
struct CapSo
{
    int x, y;
};
bool check(CapSo a, CapSo b)
{
    return a.y < b.y;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        CapSo a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i].x >> a[i].y;
        }
        sort(a, a + n, check);
        int d = 1;
        CapSo b = a[0];
        for(int i = 1; i < n; i++)
        {
            if(a[i].x > b.y) 
            {
                d++;
                b = a[i];
            }
        }
        cout << d << endl;
    }
    
    return 0;
}