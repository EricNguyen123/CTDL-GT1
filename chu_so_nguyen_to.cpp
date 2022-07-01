#include<iostream>
#include<stdbool.h>
using namespace std;
int a[5];
int x[15];
int b[5];
int n;
bool kt()
{
    if(a[x[n]] == 2) return false;
    for(int i = 1; i <= 4; i++)
    {
        b[i] = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        if(a[x[i]] == 2) b[x[i]] = 1;
        if(a[x[i]] == 3) b[x[i]] = 1;
        if(a[x[i]] == 5) b[x[i]] = 1;
        if(a[x[i]] == 7) b[x[i]] = 1;
    }
    for(int i = 1; i <= 4; i++)
    {
        if(b[i] == 0) return false;
    }
    return true;
}
void in()
{
    for(int i = 1; i <= n; i++) cout << a[x[i]];
    cout << endl;
}
void xet(int i)
{
    for(int j = 1; j <= 4; j++)
    {
        x[i] = j;
        if(i == n)
        {
            if(kt() == true)
            {
                in();
            }
        }
        else{
            xet(i + 1);
        }
        
    }
}
int main()
{
    
    cin >> n;
    
    a[1] = 2;
    a[2] = 3;
    a[3] = 5;
    a[4] = 7;
    
    xet(1);
}