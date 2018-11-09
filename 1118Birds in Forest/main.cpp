#include <bits/stdc++.h>
using namespace std;
const int Maxsize = 1e4 + 5;
int pre[Maxsize],cnt[Maxsize];
bool flag[Maxsize];
int Find(int x)
{
    int r = x,k = x,tmp;
    while(pre[r] != r) r = pre[r];
    while(k != r)//ֱ����������
    {
        tmp = pre[k];//pre[k]��ʾk���ϼ��ȱ���һ��
        pre[k] = r;
        k = tmp;//��k = tmp ��ʾ��x���ϼ�ȫ����Ҫ��Ϊ���ŵ�ֱ������
    }
    return r;//��������
}
void Union(int x,int y)
{
    int f1 = Find(x),f2 = Find(y);
    if(f1 != f2) pre[f1] = f2;
}
void getBirdsInfo()
{
    int BirdsNum = 0,BirdstreeNum = 0;
    for(int i = 0; i < Maxsize; ++i)
    {
        if(flag[i])//���������
            cnt[Find(i)]++;//ͳ����i������Ϊ�±�  ���������ж��ٸ�����
    }
    for(int i = 0; i < Maxsize; ++i)
    {
        if(flag[i] && cnt[i])//���������Ӵ��ڲ���������������Ż����Լ�������
        {
            BirdstreeNum++;//��һ�����ž�����һ����
            BirdsNum += cnt[i];//һ�������ϵ����е��ӵ��������
        }
    }
    printf("%d %d\n",BirdstreeNum,BirdsNum);
}
bool Judge(int x,int y)
{
    return Find(x) == Find(y);
}
int main()
{
    int n,k,id,tmp,q,a,b;
    scanf("%d", &n);
    for(int i = 0; i < Maxsize; ++i)
        pre[i] = i;//��Ҫ���˳�ʼ��
    for(int i = 0; i < n; ++i)
    {
        scanf("%d%d",&k,&id);
        flag[id] = true;
        while(--k)
        {
            scanf("%d",&tmp);
            Union(tmp,id);
            flag[tmp] = true;
        }
    }
    getBirdsInfo();
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d%d", &a,&b);
        printf("%s\n",Judge(a,b) ? "Yes" : "No");
    }
    return 0;
}
