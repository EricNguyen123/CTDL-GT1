#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<long long>v = vector<long long>();
    v.push_back(1);
    long long tg = 1;
    while(tg * 10 <= 1e17)
    {
        int sz = v.size();
        tg *= 10;
        v.push_back(tg);
        for(int i = 0; i < sz; i++)
        {
            v.push_back(tg + v[i]);
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        cout << upper_bound(v.begin(), v.end(), n) - v.begin() << endl;
    }
    return 0;
}