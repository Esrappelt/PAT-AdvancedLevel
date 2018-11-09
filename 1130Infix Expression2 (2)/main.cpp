#include <bits/stdc++.h>
using namespace std;
struct node
{
    int lchild,rchild;
    string data;
};
vector<node> tree;
string solve;
int root;
void inorder(int id)
{
    if(id == -1) return;
    if(id == root)
    {
        inorder(tree[id].lchild);
        solve += tree[id].data;
        inorder(tree[id].rchild);
    }
    if(tree[id].lchild == -1 && tree[id].rchild == -1) solve += tree[id].data;
    else
    {
        solve += '(';
        inorder(tree[id].lchild);
        solve += tree[id].data;
        inorder(tree[id].rchild);
        solve += ')';
    }
}
int main()
{
    int n,l,r;
    scanf("%d",&n);
    getchar();
    tree.resize(n);
    vector<bool> book(n);
    vector<string> ans;
    for(int i = 0; i < n; ++i)
    {
        string tmp;
        cin >> tmp;
        scanf("%d%d",&l,&r);
        tree[i].data = tmp;
        ans.push_back(tmp);
        tree[i].lchild = l == -1 ? -1 : l - 1;
        tree[i].rchild = r == -1 ? -1 : r - 1;
        if(l != -1) book[l-1] = true;
        if(r != -1) book[r-1] = true;
    }
    for(int i = 0; i < n; ++i)
    {
        if(book[i] == false)
        {
            root = i;
            break;
        }
    }
    inorder2(root);
    //cout << solve << endl;
    return 0;
}
