#include <bits/stdc++.h>
using namespace std;
const int Maxsize = 500 + 5,inf = 1e7;
int n,m,start,finally,w[Maxsize],weight[Maxsize],dist[Maxsize],num[Maxsize],e[Maxsize][Maxsize];
bool vis[Maxsize] = {false};
void dijkstra()
{
    for(int i = 0; i < n; ++i)
    {
        int min = inf,tmp = -1;
        for(int j = 0; j < n; ++j)
        {
            if(dist[j] < min && !vis[j])
            {
                min = dist[j];
                tmp = j;
            }
        }
        if(-1 == tmp) return;
        vis[tmp] = true;
        for(int k = 0; k < n; ++k)
        {
            if(!vis[k] && e[tmp][k] != inf)
            {
                if(dist[tmp] + e[tmp][k] < dist[k])
                {
                    dist[k] = dist[tmp] + e[tmp][k];
                    w[k] = w[tmp] + weight[k];
                    num[k] = num[tmp];
                }
                else if(dist[tmp] + e[tmp][k] == dist[k])
                {
                    num[k] += num[tmp];
                    if(w[k] < w[tmp] + weight[k])
                        w[k] = w[tmp] + weight[k];
                }
            }
        }
    }
}
void solve()
{
    int a,b,c;
    scanf("%d%d%d%d",&n,&m,&start,&finally);
    for(int i = 0; i < n; ++i) scanf("%d",&weight[i]);
    fill(e[0],e[0] + Maxsize * Maxsize,inf);
    fill(dist,dist + Maxsize,inf);
    dist[start] = 0;
    w[start] = weight[start];
    num[start] = 1;
    for(int i = 0; i < m; ++i)
    {
        scanf("%d%d%d",&a,&b,&c);
        e[a][b] = e[b][a] = c;
    }
    dijkstra();
    printf("%d %d\n",  num[finally],w[finally]);
}
int main()
{
    solve();
    return 0;
}


/*
As an emergency rescue team leader of a city, you are given a special map of your country.
 The map shows several scattered cities connected by some roads.
 Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map.
 When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible,
 and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case.
For each test case, the first line contains 4 positive integers:
 N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads,
 C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers,
  where the i-th integer is the number of rescue teams in the i-th city.
  Then M lines follow, each describes a road with three integers c1, c2 and L,
  which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the finally of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4
*/
