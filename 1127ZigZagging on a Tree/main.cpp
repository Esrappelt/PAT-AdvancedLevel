#include <bits/stdc++.h>
using namespace std;
vector<int> pre,in,post,res(31);
int maxdep,n;
vector< vector<int> > ans(31,vector<int> (31,0));//int ans[31][31];
typedef struct node
{
    int data;
    node *lchild,*rchild;
} btnode,*btree;
//根据后序中序构建二叉树
btree preorder(int root,int start,int end)
{
    if(start > end) return nullptr;
    btree b = new btnode;
    b->data = post[root];
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    b->lchild = preorder(root - (end - i + 1),start, i - 1);
    b->rchild = preorder(root - 1,i + 1,end);
    return b;
}
//根据前序中序构建二叉树
btree postorder(int root,int start,int end)
{
    if(start > end) return nullptr;
    btree b = new btnode;
    b->data = pre[root];
    int i = start;
    while(i < end && in[i] != pre[root]) i++;
    b->lchild = postorder(root + 1,start,i - 1);
    b->rchild = postorder(root + i - start + 1,i + 1,end);
    return b;
}
void dfs(btree b,int dep)
{
    if(!b)
    {
        maxdep = max(maxdep,dep);
        return;
    }
    res[dep]++;
    dfs(b->lchild,dep+1);
    dfs(b->rchild,dep+1);
}
void Levelbylevel(btree b)
{
    dfs(b,0);
    int cnt = 0,k = 0;
    queue<btree> qu;
    qu.push(b);
    while(!qu.empty())
    {
        btree tmp = qu.front();
        qu.pop();
        ans[cnt][k++] = tmp->data;
        if(k == res[cnt]) cnt++,k = 0;
        if(tmp->lchild) qu.push(tmp->lchild);
        if(tmp->rchild) qu.push(tmp->rchild);
    }
    printf("%d",ans[0][0]);
    for(k = 1; k < maxdep; ++k)
    {
        if(k & 1)//奇数
            for(int i = 0; i < res[k]; ++i) printf(" %d",ans[k][i]);
        else
            for(int i = res[k] - 1; i >= 0; --i) printf(" %d",ans[k][i]);
    }
}
int main()
{
    scanf("%d",&n);
    in.reserve(n),post.resize(n);
    for(int i = 0; i < n; ++i) scanf("%d",&in[i]);
    for(int i = 0; i < n; ++i) scanf("%d",&post[i]);
    btree b = preorder(n-1,0,n-1);
    Levelbylevel(b);
    return 0;
}
