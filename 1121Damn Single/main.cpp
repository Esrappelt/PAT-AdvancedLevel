#include <bits/stdc++.h>
using namespace std;
const int Maxsize = 1e5 + 10;
int exist[Maxsize] = {-1};
bool flag[Maxsize] = {false};
int main()
{
    vector<int> tmp;
    set<int> res;
    int a,b,t,n,m,k = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d%d",&a,&b);
        exist[a] = b;
        exist[b] = a;
    }
    scanf("%d",&m);
    for(int i = 0; i < m; ++i)
    {
        scanf("%d",&t);
        if(exist[t] == -1) res.insert(t);//�����ڵ�ֱ�ӷ������
        else
        {
            tmp.push_back(t);//���ڵķ���tmp��
            flag[t] = true;//��ʾ���ڵ�
        }
    }
    for(int i = 0; i < tmp.size(); ++i)
    {
        int x = tmp[i];
        if(flag[x])//������Ӵ���
        {
            int y = exist[x];
            if(flag[y]) flag[y] = false;//�ɷ�Ҳ��
            else res.insert(x);//�ɷ���
        }
    }
    printf("%d\n",res.size());
    for(auto it = res.begin(); it != res.end(); ++it,++k) printf("%05d%c", *it,k == res.size() - 1 ? '\n' :' ');
    return 0;
}
