#include<bits/stdc++.h>
using namespace std;
struct student { int id,moral,talent; };
bool compare(const student s1,const student s2)//总结：当要进行排序的时候  只需要比较两个变量的大小：例子如下
{
    if(s1.moral + s1.talent == s2.moral + s2.talent)//总分相同
        return s1.moral != s2.moral ? s1.moral > s2.moral : s1.id < s2.id;
    return s1.moral + s1.talent > s2.moral + s2.talent;//降序排列:左边大于右边代表降序
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
        if(temp.moral >= L && temp.talent >= L)//不低于最低分数线
        {
            if(temp.moral >= H && temp.talent >= H) ans[0].push_back(temp);//第一类:才德全尽
            else if(temp.moral >= H && temp.talent < H) ans[1].push_back(temp);//第二类:德胜才
            else if(temp.moral < H && temp.talent < H && temp.moral >= temp.talent) ans[2].push_back(temp);//第三类:才德兼亡并德胜才
            else ans[3].push_back(temp);//其它达到最低分数线的
            ++RightPeople;
        }
    }
    printf("%d\n",RightPeople);
    for(int i = 0; i < 4; ++i) sort(ans[i].begin(),ans[i].end(),compare);
    for(int i = 0; i < 4; ++i) for_each(ans[i].begin(),ans[i].end(),show);
	return 0;
}








