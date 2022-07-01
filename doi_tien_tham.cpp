#include<iostream>
using namespace std;
int a[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
int doi_tien(int n)
{
    int d = 0;
    for(int i = 0; i < 10; i++)
    {
        while(a[i] <= n)
        {
            n -= a[i];
            d++;
        }
    }
    return d;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << doi_tien(n) << endl;

    }
    return 0;
}