#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n1,n2,n3;
        cin >> n1 >> n2 >> n3;
        string s1,s2,s3;
        cin >> s1 >> s2 >> s3;
        int kq[n1 + 1][n2 + 1][n3 + 1];
        memset(kq,0,sizeof(kq));
        for(int i = 1; i <= n1; i++)
        {
            for(int j = 1; j <= n2; j++)
            {
                for(int k = 1; k <= n3; k++)
                {
                    if(s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) kq[i][j][k] = kq[i - 1][j - 1][k - 1] + 1;
                    else kq[i][j][k] = max(kq[i - 1][j][k], max(kq[i][j - 1][k], kq[i][j][k - 1]));
                }
            }
        }
        cout << kq[n1][n2][n3] << endl;
    }
    return 0;
}