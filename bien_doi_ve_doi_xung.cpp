#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s1, s2;
        cin >> s1;
        s2 = s1;
        reverse(s2.begin(), s2.end());
        vector <vector <int> > d(105, vector <int> (105, 0));
        for(int i = 0; i < s1.size(); i++)
        {
            for(int j = 0; j < s2.size(); j++)
            {
                if(s1[i] == s2[j])
                {
                    d[i + 1][j + 1] = d[i][j] + 1;
                }
                else{
                    d[i + 1][j + 1] = max(d[i][j + 1], d[i + 1][j]);
                }
            }
        }
        cout << s1.size() - d[s1.size()][s2.size()] << endl;
    }
    return 0;
}