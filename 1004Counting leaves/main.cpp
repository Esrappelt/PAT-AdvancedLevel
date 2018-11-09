#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
map<int,vector<int> > ans;
int maxdepth = -1;
vector<int> res(101),level(101);
//�ⷨһ:������ȱ���
void dfs(int root,int dep)
{
	if(!ans[root].size())//����Ԫ��Ϊ���ʱ����ǵݹ�Ľ�������
	{
		res[dep]++;//ͳ��û�к��ӵ���ȼ����
		maxdepth = maxdepth > dep ? maxdepth : dep;
		return;
	}
	else
		for(vector<int>::iterator it = ans[root].begin(); it != ans[root].end(); ++it)
			dfs(*it,dep+1);
}
void bfs()
{
	int dep = 0;
	queue<int> q1;
	q1.push(1);
	while(!q1.empty())
	{
		queue<int> q2;
		while(!q1.empty())
		{
			int tmp = q1.front();
			q1.pop();
			if(!ans[tmp].size())
				level[dep]++;
			for(vector<int>::iterator it = ans[tmp].begin(); it != ans[tmp].end(); ++it)
				q2.push(*it);
		}
		dep++;//��μ�һ
		q1 = q2;
	}
	for(int i = 0; i < dep; ++i)
		printf("%d%c",level[i],i == dep - 1 ? '\n' : ' ');
}
int main()
{
	int id,i,j,k,N,M;
	scanf("%d%d",&N,&M);
	for(i = 0; i < M; ++i)
	{
		scanf("%d%d",&id,&k);
		vector<int> tmp(k);
		for(j = 0; j < k; ++j) scanf("%d",&tmp[j]);
		ans.insert(pair<int,vector<int> >(id,tmp));
	}
	/*dfs(1,0);
	for(i = 0; i <= maxdepth; ++i)
		printf("%d%c",res[i],i == maxdepth ? '\n': ' ');*/
	bfs();
	return 0;
}