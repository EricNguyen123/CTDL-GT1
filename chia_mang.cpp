#include<iostream>
using namespace std;
int n, k, sum, a[30];
int d, snhom;
bool x[30], z[30];
int y[30];
int dem;
void nhap()
{
	dem = snhom = d = sum = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
		x[i] = false;
		z[i] = false;
	}
}

void cap_nhat(int l)
{
	
	dem++;
	int p = 1;
	for(int j = 1; j <= n; j++)
	{
		if(y[p] == a[j])
		{
			z[j] = true;
			if(p == l)
			{
				break;
			}
			p++;
		}
	}
}
void xu_ly(int i)
{
	for(int j = 1; j <= n; j++)
	{
		if(x[j] == false && z[j] == false)
		{
			y[i] = a[j];
			x[j] = true;
			sum += y[i];
			if(sum == snhom)
			{
				/*for(int l = 1; l <= i; l++)
				{
					cout << y[l] << " ";
				}
				cout << endl;
				for(int jj = 1; jj <= n; jj++)
				{
					cout << x[jj] << "+ " << z[jj] << " ";
				}
				cout << endl;*/
				cap_nhat(i);
			}
			else if(sum < snhom)
			{
				xu_ly(i + 1);
			}
			sum -= y[i];
			x[j] = false;
		}
	}
}
void kiem_duyet()
{
	if(sum % k == 0)
	{
		snhom = sum / k;
		sum = 0;
		xu_ly(1);
	}
	else
	{
		d = 1;
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		nhap();
		kiem_duyet();
		if(d == 1)
		{
			cout << 0 << endl;
		}
		else
		{
			if(dem == k)
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 1 << endl;
			}
		}
	}
	return 0;
}
