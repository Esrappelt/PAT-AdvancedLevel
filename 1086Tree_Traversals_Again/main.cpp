#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<int> pre,in;
void post(int root,int start,int end)
{
    if(start > end)
        return;
    int i = start;
    while(i < end && in[i] != pre[root]) i++;
    post(root + 1,start,i - 1);
    post(root + i - start + 1,i + 1,end);
    ans.push_back(pre[root]);
}
int main()
{
    int n,data;
    stack<int> st;
    string tmp;
    scanf("%d", &n);
    for(int i = 0; i < 2 * n; ++i)
    {
        cin >> tmp;
        if("Pop" == tmp )
        {
            in.push_back(st.top());
            st.pop();
        }
        else
        {
            cin >> data;
            st.push(data);
            pre.push_back(data);
        }
    }
    post(0,0,n - 1);
    for(int i = 0; i < ans.size(); ++i)
    {
        printf("%d",ans[i]);
        if(i < ans.size() - 1)
            printf(" ");
    }
    return 0;
}
