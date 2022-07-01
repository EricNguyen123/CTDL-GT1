#include<iostream>
using namespace std;
string res[105];
string operator +(string a, string b)
{
    int m = a.size();
    int n = b.size();
    while(m < n)
    {
        a = "0" + a;
        m++;
    }
    while(m > n)
    {
        b = "0" + b;
        n++;
    }
    string s = "";
    int nho = 0;
    for(int i = m - 1; i >= 0; i--)
    {
        int c = int(a[i] - '0') + int(b[i] - '0') + nho;
        if(c > 9)
        {
            s = char(c - 10 + '0') + s;
            nho = 1;
        }
        else
        {
            s = char(c + '0') + s;
            nho = 0;
        }
    }
    if(nho)
    {
        s = '1' + s;
    }
    return s;
}
string operator *(string a, string b)
{
    int m = a.size();
    int n = b.size();
    string s0 = "0";
    int nho = 0;
    int l = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        string s = "";
        for(int j = m - 1; j >= 0; j--)
        {
            int c = int(a[j] - '0') * int(b[i] - '0') + nho;
            if(c > 9)
            {
                s = char(c % 10 + '0') + s;
                nho = c / 10; 
            }
            else{
                s = char(c + '0') + s;
                nho = 0;
            }
        }
        if(nho > 0)
        {
            s = char(nho + '0') + s;
            nho = 0;
        }
        for(int k = 0; k < l; k++)
        {
            s = s + '0';
        }
        l++;
        s0 = s0 + s;
    }
    
    return s0;
}
void khoi_tao()
{
    res[0] = "1";
    res[1] = "1";
    res[2] = "2";
    for(int i = 3; i <= 101; i++)
    {
        string s = "";
        if(i % 2 == 0)
        {
            for(int j = 0; j <= (i - 1) / 2; j++)
            {
                s = s + res[j] * res[i - j - 1];
            }
            s = s + s;
        }
        else{
            for(int j = 0; j < (i - 1) / 2; j++)
            {
                s = s + res[j] * res[i - j - 1];
            }
            s = s + s;
            s = s + res[(i - 1) / 2] * res[(i - 1) / 2];
        }
        res[i] = s;
    }
}
int main()
{
    khoi_tao();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n == 0) cout << 0 << endl;
        else{
             cout << res[n] << endl;
        }
    }
    return 0;
}