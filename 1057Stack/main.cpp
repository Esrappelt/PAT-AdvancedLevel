#include <bits/stdc++.h>
using namespace std;
#define lowbit(i) ( (i) & (-i) )
const int maxn = 100001;
int tree[maxn];
stack<int> st;
void add(int x,int y)
{
    for(int i = x; i <= maxn; i += lowbit(i))
        tree[i] += y;
}
int getSum(int i)//获得0~i区间的和
{
    int sum = 0;
    while(i)
    {
        sum += tree[i];
        i -= lowbit(i);
    }
    return sum;
}
void PeekMedian1()
{
    int low = 0,high = maxn - 1,mid,k = (st.size() + 1) / 2;
    while(low < high)
    {
        mid = (low + high) >> 1;
        if(getSum(mid) >= k)
            high = mid;
        else
            low =  mid + 1;
    }
    printf("%d\n",high);
}
int main()
{
    char str[12];
    int n,key;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s",str);
        if(str[1] == 'u')
        {
            scanf("%d", &key);
            st.push(key);
            add(key,1);
        }
        else if(str[1] == 'o')
        {
            if(!st.empty())
            {
                add(st.top(),-1);
                printf("%d\n",st.top());
                st.pop();
            }
            else
                printf("Invalid\n");
        }
        else
        {
            if(st.empty())
                printf("Invalid\n");
            else
                PeekMedian1();
        }
    }
    return 0;
}
