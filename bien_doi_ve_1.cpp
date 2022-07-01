#include<iostream>
#include<algorithm>
using namespace std;
int x[100005];
void khoi_tao()
{
	x[1] = 0;
	x[2] = 1;
	x[3] = 1;
	int i = 4;
	while(i <= 100000)
	{
		int a, b, c;
		if(i % 2 == 0 )
		{
			a = min(x[i - 1], x[i / 2]);
			c = a;
		}
		
		if(i % 3 == 0)
		{
			b = min(x[i - 1], x[i / 3]);
			c = b;
		}
		
		if(i % 2 == 0 && i % 3 == 0)
		{
			c = min(a, b);
		}
		else if(i % 2 != 0 && i % 3 != 0)
		{
			c = x[i - 1];
		}
		x[i] = c + 1;
		i++;
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
		cout << x[n] << endl;
	}
	return 0;
}
