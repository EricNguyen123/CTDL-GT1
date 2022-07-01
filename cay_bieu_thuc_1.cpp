#include<iostream>
#include<stack>
using namespace std;
typedef struct Node
{
    char c;
    Node *left;
    Node *right;
}*Tree;
Tree getNode()
{
    Tree p;
    p = new Node;
    return p;
}
Tree Tao(char c)
{
    Tree res = getNode();
    res->c = c;
    res->left=res->right=NULL;
    return res;
}
void goi(Tree a)
{
    if(a != NULL)
    {
        goi(a->right);
        cout << a->c << " ";
        goi(a->left);
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        stack<Tree>st=stack<Tree>();
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                Tree tg = Tao(s[i]);
                tg->left = st.top();
                st.pop();
                tg->right = st.top();
                st.pop();
                st.push(tg);
            }
            else st.push(Tao(s[i]));
        }
        goi(st.top());
        cout << endl;
    }
    return 0;
}