#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}btnode,*btree;


void Init(btree &b)
{
    b = new btnode;
    assert(b!=nullptr);
    b->lchild = nullptr;
    b->rchild = nullptr;
}


btree CreateBT2(int *post,int *in,int n)
{
    if(n <= 0)
        return nullptr;
    int r = *(post + n - 1),*p;//后序的最后一个位置，取值
    btree b = new btnode;
    b->data = r;//把值赋给b
    for(p = in; p < in + n; ++p)//在中序里查找r即根节点
        if(*p == r)
            break;
    int k = p - in;//k为根节点在in中的下标
    b->lchild = CreateBT2(post,in,k);//左子树有k个结点
    b->rchild = CreateBT2(post + k,p + 1,n - k - 1);//右子树有n - k - 1个结点,p + 1代表右子树
    return b;
}


void Traverse(btree root)
{
    btree tmp;
    vector<int> ans;
    queue<btree> qu;
    qu.push(root);
    while(!qu.empty())
    {
        tmp = qu.front();
        ans.push_back(tmp->data);
        qu.pop();
        if(tmp->lchild)
            qu.push(tmp->lchild);
        if(tmp->rchild)
            qu.push(tmp->rchild);
    }
    for(unsigned i = 0; i < ans.size(); ++i)
    {
        printf("%d",ans[i]);
        if(i < ans.size() - 1)
            printf(" ");
    }
}



int main()
{
    btree root;
    Init(root);
    int n;
    scanf("%d", &n);
    int post[n],in[n];
    for(int i = 0; i < n; ++i)
        scanf("%d",post + i);
    for(int i = 0; i < n; ++i)
        scanf("%d",in + i);
    root = CreateBT2(post,in,n);
    Traverse(root);
    return 0;
}
/*
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2
*/
