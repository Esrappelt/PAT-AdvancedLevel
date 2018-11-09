#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}bstnode,*bstree;
void Insert(bstree &b,int data)
{
    if(!b)
    {
        b = new bstnode;
        assert(b);
        b->lchild  = b->rchild = NULL;
        b->data = data;
    }
    else if(data <= b->data)
        Insert(b->lchild,data);
    else
        Insert(b->rchild,data);
}

//解法一：//先求出深度，再求出第几层的结点数目~~
int Depth(bstree b)
{return !b ? 0 : 1 + max(Depth(b->lchild),Depth(b->rchild));}
int Count(int ans,bstree b,int k)
{
    if(!b) return 0;
    if(k == 0) ans++;
    else if(k)
    {
        Count(ans,b->lchild,k - 1);
        Count(ans,b->rchild,k - 1);
    }
    return ans;
}
void solve1(bstree b)
{
    int dep = Depth(b);
    printf("%d + %d = %d\n",Count(0,b,dep - 1),Count(0,b,dep - 2),Count(0,b,dep - 1) + Count(0,b,dep - 2));
}
//解法二:
vector<int> res(1000);
int bdepth;
void dfs(bstree b,int dep)
{
    if(!b)
    {
        bdepth = max(bdepth,dep);
        return;
    }
    res[dep]++;//统计相应的深度的结点个数,最后输出res[bdepth-1]和res[bdepth-2]
    dfs(b->lchild,dep+1);
    dfs(b->rchild,dep+1);
}
void solve2(bstree b)
{
    dfs(b,0);
    printf("%d + %d = %d\n",res[bdepth-1],res[bdepth-2],res[bdepth-1]+res[bdepth-2]);
}
int main()
{
    int n;
    bstree b = NULL;
    scanf("%d", &n);
    vector<int> bt(n);
    for(int i = 0; i < n; ++i)
        scanf("%d",&bt[i]);
    for(int i = 0; i < n; ++i)
        Insert(b,bt[i]);
    //解法一:
    //solve1(b);
    //解法二:
    solve2(b);
    return 0;
}
/*
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Insert a sequence of numbers into an initially empty binary search tree. Then you are supposed to count the total number of nodes in the lowest 2 levels of the resulting tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=1000) which is the size of the input sequence. Then given in the next line are the N integers in [-1000 1000] which are supposed to be inserted into an initially empty binary search tree.

Output Specification:

For each case, print in one line the numbers of nodes in the lowest 2 levels of the resulting tree in the format:

n1 + n2 = n

where n1 is the number of nodes in the lowest level, n2 is that of the level above, and n is the sum.

Sample Input:
9
25 30 42 16 20 20 35 -5 28
Sample Output:
2 + 4 = 6
*/
