#include <bits/stdc++.h>
using namespace std;
struct node
{
    string name;
    int height;
    bool operator<(const node &v) const { return height != v.height ? height > v.height : name < v.name; }//жиди<
};
int main()
{
    int n,k,last_row,row,height,row_n;
    scanf("%d%d",&n,&k);
    row = n / k,last_row = n / k + n % k;
    vector<node> photo(n);
    for(int i = 0; i < n; ++i)
    {
        char name[10];
        scanf("%s%d",name,&height);
        photo.push_back(node{name,height});
    }
    sort(photo.begin(),photo.end());
    for(int i = 0,h = 0; i < k; ++i)
    {
        row_n = i == 0 ? last_row : row;
        vector<string> ans(row_n);
        for(int j = row_n / 2,m = h; j < row_n; ++j,m += 2) ans[j] = photo[m].name;
        for(int j = row_n / 2 - 1,m = h + 1; j >= 0; --j,m += 2) ans[j] = photo[m].name;
        for(int j = 0; j < row_n; ++j) printf("%s%c",ans[j].c_str(), j == row_n - 1 ? '\n' : ' ');
        h += row_n;
    }
    return 0;
}
