#include<iostream>
#include<stack>
using namespace std;
int n, m, a[50][50];
void Init()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
}
int KiemTra_DDEuler(int u)
{
    int i, j, s, d;
    d = 0;
    int v = 0;
    for(i = 1; i <= n;i++){
        s = 0;
        for(j = 1; j <= n; j++) s += a[i][j];
        if(s % 2 != 0)
        {
            d++; 
            if(u == i) v = 1;
        }
    }
    if(d == 2 && v == 1) return 1; 
    return 0;
}
void DDEuler(int u)
{
    int x, v;
    stack<int>st=stack<int>();
    int CE[50];
    st.push(u);
    int dCE = 0;
    do{
        v = st.top();
        x = 1;
        while(x <= n && a[v][x] == 0)
        {
            x++;
        }
        if(x > n)
        {
            dCE++;
            CE[dCE] = v;
            st.pop();
        }
        else{
            st.push(x);
            a[v][x] = 0;
            a[x][v] = 0;
        }
    }while(!st.empty());
    for(int i = dCE; i > 0; i--)
    {
        cout << CE[i] << " ";
    }
    cout << endl;
}
int Kiemtra_EulerCycle(){
    int i, j, s, d;
    d = 0;
    for(i = 1; i <= n; i++){ 
        s = 0;
        for(j = 1; j <= n; j++) s += a[i][j];
        if(s % 2 != 0) d++; 
    }
    if(d > 0) return 0;
    return 1; 
}
void EulerCycle(int u){
    int v, x, dCE;
    int CE[50]; 
    stack<int>st=stack<int>();
    st.push(u);
    dCE=0; 
    do {
        v = st.top();
        x = 1;
            while (x <= n && a[v][x] == 0) x++; 
            if (x>n) {
                dCE++; 
                CE[dCE]=v; 
                st.pop();
            }
            else {
                st.push(x);
                a[v][x] = 0; 
                a[x][v] = 0; 
            }
    } while(!st.empty());
    for( x = dCE; x > 0; x--) cout << CE[x] << " ";
    cout << endl;
}
int main()
{
    Init();
    if(Kiemtra_EulerCycle() == 1 && KiemTra_DDEuler(m) == 1)
    {
        EulerCycle(m);
        DDEuler(m);
    }
    else{
        cout << "no Euler cycle" << endl;
    }
   
    return 0;
}