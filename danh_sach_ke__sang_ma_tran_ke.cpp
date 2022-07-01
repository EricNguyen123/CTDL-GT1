#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    int x[n + 5][n + 5];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            x[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string word;
        while(ss >> word)
        {
            int a = 0;
            for(int i = 0; i < word.size(); i++)
            {
                a = a * 10 + int(word[i] - '0');
            }
            x[i][a] = x[a][i] = 1;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}