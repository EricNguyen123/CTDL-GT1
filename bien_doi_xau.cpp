#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s1,s2;
        cin >> s1 >> s2;
        int a[1005][1005];
        for(int i = 0; i <= s1.size(); i++)
        {
            a[i][0] = i;
        }
        for(int i = 0; i <= s2.size(); i++)
        {
            a[0][i] = i;
        }
        for(int i = 1; i <= s1.size(); i++)
        {
            for(int j = 1; j <= s2.size(); j++)
            {
                if(s1[i - 1] == s2[j - 1])
                {
                    a[i][j] = a[i - 1][j - 1];
                }
                else{
                    a[i][j] = min(a[i - 1][j - 1], min(a[i - 1][j], a[i][j - 1])) + 1;
                }
            }
        }
        cout << a[s1.size()][s2.size()] << endl;
    }
    return 0;
}