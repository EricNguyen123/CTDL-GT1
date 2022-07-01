#include<iostream>
using namespace std;
long b[10];
long c[105];
long mod = 1e9 + 7;
void khoitao()
{
    c[1] = 10;
    b[0] = 0;
    for(int i = 1; i <= 9; i++) b[i] = 1;
    for(int i = 2; i < 101; i++)
    {
        c[i] = 0;
        for(int j = 1; j <= 9; j++)
        {
            b[j] = (b[j] + b[j - 1]) % mod;
            c[i] = (c[i] + b[j]) % mod;
        }
        c[i] = (c[i] + c[i - 1]) % mod;
    }
}
int main()
{
    int t;
    cin >> t;
    khoitao();
    while (t--)
    {
        int n;
        cin >> n;
        cout << c[n] << endl;
    }
    
    return 0;
}