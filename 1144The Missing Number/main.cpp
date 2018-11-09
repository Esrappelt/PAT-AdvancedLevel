#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    map<int,int> ans;
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&t);
        ans[t]++;
    }
    for(int i = 1; i <= INT_MAX; ++i) {
        if(ans[i] == 0) {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}
