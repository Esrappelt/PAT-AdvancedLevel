#include<bits/stdc++.h>
using namespace std;
struct student { int id,moral,talent; };
bool compare(const student s1,const student s2)//�ܽ᣺��Ҫ���������ʱ��  ֻ��Ҫ�Ƚ����������Ĵ�С����������
{
    if(s1.moral + s1.talent == s2.moral + s2.talent)//�ܷ���ͬ
        return s1.moral != s2.moral ? s1.moral > s2.moral : s1.id < s2.id;
    return s1.moral + s1.talent > s2.moral + s2.talent;//��������:��ߴ����ұߴ�����
}
void show(const student iter) {printf("%08d %d %d\n",iter.id,iter.moral,iter.talent);}
int main()
{
    int N,L,H,RightPeople = 0;
    scanf("%d%d%d",&N,&L,&H);
    vector<student> ans[4];
    for(int i = 0; i < N; ++i)
    {
        student temp;
        scanf("%d%d%d",&temp.id,&temp.moral,&temp.talent);
        if(temp.moral >= L && temp.talent >= L)//��������ͷ�����
        {
            if(temp.moral >= H && temp.talent >= H) ans[0].push_back(temp);//��һ��:�ŵ�ȫ��
            else if(temp.moral >= H && temp.talent < H) ans[1].push_back(temp);//�ڶ���:��ʤ��
            else if(temp.moral < H && temp.talent < H && temp.moral >= temp.talent) ans[2].push_back(temp);//������:�ŵ¼�������ʤ��
            else ans[3].push_back(temp);//�����ﵽ��ͷ����ߵ�
            ++RightPeople;
        }
    }
    printf("%d\n",RightPeople);
    for(int i = 0; i < 4; ++i) sort(ans[i].begin(),ans[i].end(),compare);
    for(int i = 0; i < 4; ++i) for_each(ans[i].begin(),ans[i].end(),show);
	return 0;
}








