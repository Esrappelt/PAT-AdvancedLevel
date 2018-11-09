#include <bits/stdc++.h>
using namespace std;
int n,m;
typedef struct Anode
{
    int adjvex;
    Anode *next;
}Arcnode;

typedef struct Vnode
{
    int data;
    Arcnode *first;
}Vnode;

typedef struct
{
    Vnode adjlist[201];
    int arcnum,vexnum;
}Adjnode,*Adjgraph;


int locate(Adjgraph G,int data)
{
    for(int i = 0; i < G->vexnum; ++i)
    {
        if(data == G->adjlist[i].data)
            return i;
    }
    return -1;
}

void Create(Adjgraph &G)
{
    Arcnode *p;
    int i,j,k,v1,v2;
    G = new Adjnode;
    G->arcnum = m;
    G->vexnum = n;
    for(int i = 0; i < G->vexnum; ++i)
    {
        G->adjlist[i].data = i + 1;
        G->adjlist[i].first = nullptr;
    }
    for(k = 0; k < G->arcnum; ++k)
    {
        scanf("%d%d",&v1,&v2);
        i = locate(G,v1);
        j = locate(G,v2);
        p = new Arcnode;
        assert(p);
        p->adjvex = j;
        p->next = G->adjlist[i].first;
        G->adjlist[i].first = p;
        p = new Arcnode;
        assert(p);
        p->adjvex = i;
        p->next = G->adjlist[j].first;
        G->adjlist[j].first = p;
    }
}
bool Judge(Adjgraph G,vector<int> ans,vector<int> res)
{
    if(ans.size() != G->vexnum + 1 || ans[0] != ans[ans.size() - 1])
        return false;
    Arcnode *p;
    for(unsigned int i = 0; i < ans.size() - 1; ++i)
    {
        int j = locate(G,ans[i]);
        for(p = G->adjlist[j].first; p != nullptr; p = p->next)
        {
            if(G->adjlist[p->adjvex].data == ans[i+1]) break;
        }
        if(!p || (i == 0 && res[ans[i]] != 2 )|| (i != 0 && res[ans[i]] != 1))
            return false;
    }
    return true;
}
void solve(Adjgraph G)
{
    int k,r,val;
    scanf("%d", &k);
    while(k--)
    {
        scanf("%d",&r);
        vector<int> ans,res(n+1,0);
        for(int i = 0; i < r; ++i)
        {
            scanf("%d",&val);
            ans.push_back(val);
            res[val]++;
        }
        if(Judge(G,ans,res))
            printf("YES\n");
        else
            printf("NO\n");
    }
}
int main()
{
    Adjgraph G;
    scanf("%d%d",&n,&m);
    Create(G);
    solve(G);
    return 0;
}
/*
1122. Hamiltonian Cycle (25)
时间限制
300 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
The "Hamilton cycle problem" is to find a simple cycle that contains every vertex in a graph. Such a cycle is called a "Hamiltonian cycle".

In this problem, you are supposed to tell if a given cycle is a Hamiltonian cycle.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers N (2< N <= 200), the number of vertices, and M, the number of edges in an undirected graph. Then M lines follow, each describes an edge in the format "Vertex1 Vertex2", where the vertices are numbered from 1 to N. The next line gives a positive integer K which is the number of queries, followed by K lines of queries, each in the format:

n V1 V2 ... Vn

where n is the number of vertices in the list, and Vi's are the vertices on a path.

Output Specification:

For each query, print in a line "YES" if the path does form a Hamiltonian cycle, or "NO" if not.

Sample Input:
6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
6
7 5 1 4 3 6 2 5
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 3 4 5 2 6
7 6 1 2 5 4 3 1
Sample Output:
YES
NO
NO
NO
YES
NO
*/
