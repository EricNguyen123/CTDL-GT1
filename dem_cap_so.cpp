#include<iostream>
#include<algorithm>
using namespace std;
int d;
void xet(int l, int r, int a[], int Min)
{
            if(l <= r)
            {
                int mid = (l + r) / 2;
                if(a[mid] > Min)
                {
                    d = 1;
                    return;
                }
                else{
                    xet(l, mid - 1, a, Min);
                    xet(mid + 1, r, a, Min);
                }
            }
            else return;
}
int main()
{
    int t;
    cin >> t;
    int a[t];
    for(int i = 0; i < t; i++)
    {
        cin >> a[i];
    }
    int kq = 0;
    for(int i = 0; i < t; i++)
    {
        for(int j = i + 1; j < t; j++)
        {
            d = 0;
            int Min = min(a[i], a[j]);
            xet(i + 1, j - 1, a, Min);
            if(d == 0) kq++;
        }
    }
    cout << kq << endl;
    return 0;
}