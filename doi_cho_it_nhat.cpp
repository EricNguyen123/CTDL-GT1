#include<iostream>
#include<algorithm>
using namespace std;
void swap(int *a, int *b)
{
	int tg = *a;
	*a = *b;
	*b = tg;
}
void dem(int a[], int n)
{
	int i, j, min_indx, d = 0;
	for(i = 0; i < n - 1; i++)
	{
		min_indx = i;
		for(j = i + 1; j < n; j++)
		{
			if(a[j] < a[min_indx])
			{
				min_indx = j;
			}
		}
		if(min_indx != i)
		{
			d++;
		}
		swap(&a[i], &a[min_indx]);
	}
	cout << d << endl;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		dem(a, n);
	}
	return 0;
}
