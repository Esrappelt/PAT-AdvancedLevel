#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int addrss;
    int data;
    int Nextaddress;
};

bool cmp(const node &x,const node &y)
{return x.data < y.data;}

int main()
{
    int N,i;
    vector<node> ans,res(100000);
    node temp;
    int first;
    scanf("%d %05d",&N,&first);
    for(i = 0; i < N; ++i)
    {
        scanf("%05d %d %05d",&temp.addrss,&temp.data,&temp.Nextaddress);
        res[temp.addrss] = temp;
    }
    if(-1 == first)
    {
        printf("0 -1\n");
        return 0;
    }
    while(first != -1)//装入有效的结点
    {
        ans.push_back(res[first]);
        first = res[first].Nextaddress;
    }
    sort(ans.begin(),ans.end(),cmp);
    printf("%d %05d\n",ans.size(),ans[0].addrss);
    for(i = 0; i < ans.size() - 1; i++)
        printf("%05d %d %05d\n",ans[i].addrss,ans[i].data,ans[i+1].addrss);
    printf("%05d %d -1\n",ans[i].addrss,ans[i].data);
	return 0;
}

//注释
/*
A linked list consists of a series of structures, which are not necessarily adjacent in memory. We assume that each structure contains an integer key and a Next pointer to the next structure. Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive N (< 105) and an address of the head node, where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Key Next

where Address is the address of the node in memory, Key is an integer in [-105, 105], and Next is the address of the next node. It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.

Output Specification:

For each test case, the output format is the same as that of the input, where N is the total number of nodes in the list and all the nodes must be sorted order.

Sample Input:
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
Sample Output:
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
*/
