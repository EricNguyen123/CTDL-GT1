#include<iostream>
#include<queue>
#include<string>
#include<stack>
using namespace std;
typedef struct Node
{
    string c;
    Node *left;
    Node *right;
}*Tree;
Tree getNode()
{
    Tree p;
    p = new Node;
    return p;
}
Tree Tao(string c)
{
    Tree res = getNode();
    res->c = c;
    res->left=res->right=NULL;
    return res;
}
long long so(string a)
{
    long long b = 0;
    for(int i = 0; i < a.size(); i++)
    {
        b = b * 10 + int(a[i] - '0');
    }
    return b;
}

string p;
void goi(Tree a)
{
    if(a != NULL)
    {
        goi(a->left);
        p = p + a->c + " ";
        goi(a->right);
    }
}
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin, s);
        s += "_";
        queue<Tree>st=queue<Tree>();
        int i = s.rfind(" ");
        while(i > -1)
        {
            string v = "";
            int j = i + 1;
            while(s[j] != '_')
            {
                v = v + s[j];
                j++;
            }
            if(v == "+" || v == "-" || v == "*" || v == "/")
            {
                Tree tg = Tao(v);
                tg->right = st.front();
                st.pop();
                tg->left = st.front();
                st.pop();
                st.push(tg);
            }
            else st.push(Tao(v));
            s = s.replace(i, 1, "_");
            i = s.rfind(" ");
        }
        string v = "";
        int j = 0;
            while(s[j] != '_')
            {
                v = v + s[j];
                j++;
            }
            if(v == "+" || v == "-" || v == "*" || v == "/")
            {
                Tree tg = Tao(v);
                tg->right = st.front();
                st.pop();
                tg->left = st.front();
                st.pop();
                st.push(tg);
            }
        p = "";
        goi(st.front());
        i = p.find(" ");
        j = 0;
        stack<long long>q = stack<long long>();
        string c;
        while(i > -1)
        {
            p = p.replace(i, 1, "_");
            string v = "";
            while(p[j] != '_')
            {
                v = v + p[j];
                j++;
            }
            j++;
            if(v == "+" || v == "-" || v == "*" || v == "/")
            {
                c = v;
            }
            else 
            {
                q.push(so(v));
                if(q.size() == 2)
                {
                    long long m = q.top();
                    q.pop();
                    long long n = q.top();
                    q.pop();
                    if(c == "+") q.push(n + m);
                    if(c == "-") q.push(n - m);
                    if(c == "*") q.push(n * m);
                    if(c == "/") q.push(n / m);
                }
            }
            i = p.find(" ");
        }
        v = "";
            while(j < p.size())
            {
                v = v + p[j];
                j++;
            }
            q.push(so(v));
            long long m = q.top();
                    q.pop();
                    long long n = q.top();
                    q.pop();
                    if(c == "+") q.push(n + m);
                    if(c == "-") q.push(n - m);
                    if(c == "*") q.push(n * m);
                    if(c == "/") q.push(n / m);
        cout << q.top() << endl;
    }
    return 0;
}