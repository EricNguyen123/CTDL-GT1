#include<iostream>
#include<stdbool.h>
#include<algorithm>
using namespace std;
int n, k, x[110], a[110];
void nhap()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	x[0] = 0;
}
bool kiemtra()
{
	for(int i = 1; i < k; i++)
	{
		if(a[x[i]] > a[x[i + 1]])
		{
			return false;
		}
	}
	return true;
}
void in()
{
    for(int i = 1; i <= k; i++)
	{
		cout << a[x[i]] << " ";
	}
    cout << endl;
}
void xuly(int i)
{
	for(int j = x[i - 1] + 1; j <= n - k + i; j++)
	{
		x[i] = j;
		if(i == k)
		{
			if(kiemtra() == true)
			{
				in();
			}
		}
		else
		{
			xuly(i + 1);
		}
	}
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        nhap();
        xuly(1);
    }
	
	return 0;
}
