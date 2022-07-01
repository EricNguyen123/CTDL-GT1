#include<iostream>
#define MAX 50
#define TRUE 1
#define FALSE 0
using namespace std;
int n, m;
int A[MAX][MAX];
int B[MAX][MAX];
int a[MAX];
int Max;
int dem;
void Init()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			A[i][j] = B[i][j] = 0;
		}
	}
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		A[x + 1][y + 1] = A[y + 1][x + 1] = 1;	
		B[x + 1][y + 1] = B[y + 1][x + 1] = 1;
	}
	Max = 0;
}

int kiem_tra()
{
	int s, d;
	d = 0;
	for(int i = 1; i <= n; i++)
	{
		s = 0;
		for(int j = 1; j <= n; j++)
		{
			s += A[i][j];
		}
		if(s % 2 != 0)
		{
			d++;
			a[d] = i;
		}
	}
	dem = d;
	if(d != 2)
	{
		return FALSE;
	}
	return TRUE;
}

void DDEULER(int u)
{
	int v, x, top, dCE;
	int stack[MAX], CE[MAX];
	top = 1;
	stack[top] = u;
	dCE = 0;
	do
	{
		v = stack[top];
		x = 1;
		while(x <= n && A[v][x] == 0)
		{
			x++;
		}
		if(x > n)
		{
			break;
			dCE++;
			CE[dCE] = v;
			top--;
		}
		else
		{
			top++;
			stack[top] = x;
			A[v][x] = 0;
			A[x][v] = 0;
		}
	}while(top != 0);
	if(top > Max)
	{
		Max = top - 1;
	}
	for(x=1; x<=top; x++)
	{
		cout << stack[x] << " ";
	}
	cout << endl;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			A[i][j] = B[i][j];
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		Init();
		//if(kiem_tra() == TRUE)
		//{
			for(int i = 1; i <= n; i++)
			{
				DDEULER(i);
			}
		//}
		cout << Max << endl;
	}
}
