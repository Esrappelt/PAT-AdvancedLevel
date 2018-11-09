#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string d;
    cin >> d >> n;
    while(--n) {
        string ans;
        for(int i = 0; i < d.size(); ++i) {
            int cnt = 1;
            while(i < d.size() - 1 && d[i] == d[i+1]) {
                i++;
                cnt++;
            }
            ans.push_back(d[i]);
            ans.push_back(cnt+'0');
        }
        d = ans;
    }
    cout << d << endl;
    return 0;
}
