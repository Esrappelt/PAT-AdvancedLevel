#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,ak,bk,m = 0,n = 0;
    string a,b,ans1,ans2;
    cin >> k >> a >> b;
    ak = a.length(),bk = b.length();
    for(int i = 0; i < a.length(); ++i)
        if(a[i] == '.') { ak = i; break;}
    for(int i = 0; i < b.length(); ++i)
        if(b[i] == '.') { bk = i; break;}
    while(a[m] == '.' || a[m] == '0') ++m;
    while(b[n] == '.' || b[n] == '0') ++n;
    ak = ak >= m ? (ak - m) : (ak + 1 - m);
    bk = bk >= n ? (bk - n) : (bk + 1 - n);
    ak = (m == a.length()) ? 0 : ak;
    bk = (n == b.length()) ? 0 : bk;
    for(int i = 0; i < k; ++i)
    {
        if(a[m] != '.' && m < a.length()) ans1.push_back(a[m]);
        else if(m >= a.length()) ans1.push_back('0');
        ++m;
    }
    for(int i = 0; i < k; ++i)
    {
        if(b[n] != '.' && n < b.length()) ans2.push_back(b[n]);
        else if(n >= b.length()) ans2.push_back('0');
        ++n;
    }
    if(ans1 == ans2 && ak == bk) printf("YES 0.%s*10^%d",ans1.c_str(),ak);
    else printf("NO 0.%s*10^%d 0.%s*10^%d",ans1.c_str(),ak,ans2.c_str(),bk);
    return 0;
}
/*
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int n, p = 0, q = 0;
    char a[10000], b[10000], A[10000], B[10000];
    scanf("%d%s%s", &n, a, b);
    int cnta = strlen(a), cntb = strlen(b);
    for(int i = 0; i < strlen(a); i++) {
        if(a[i] == '.') {
            cnta = i;
            break;
        }
    }
    for(int i = 0; i < strlen(b); i++) {
        if(b[i] == '.') {
            cntb = i;
            break;
        }
    }
    int indexa = 0, indexb = 0;
    while(a[p] == '0' || a[p] == '.') p++;
    while(b[q] == '0' || b[q] == '.') q++;
    if(cnta >= p)
        cnta = cnta - p;
    else
        cnta = cnta - p + 1;
    if(cntb >= q)
        cntb = cntb - q;
    else
        cntb = cntb - q + 1;
    if(p == strlen(a))
        cnta = 0;
    if(q == strlen(b))
        cntb = 0;
    while(indexa < n) {
        if(a[p] != '.' && p < strlen(a))
            A[indexa++] = a[p];
        else if(p >= strlen(a))
            A[indexa++] = '0';
        p++;
    }
    while(indexb < n) {
        if(b[q] != '.' && q < strlen(b))
            B[indexb++] = b[q];
        else if(q >= strlen(b))
            B[indexb++] = '0';
        q++;
    }
    if(strcmp(A, B) == 0 && cnta == cntb)
        printf("YES 0.%s*10^%d", A, cnta);
    else
        printf("NO 0.%s*10^%d 0.%s*10^%d" , A, cnta, B, cntb);
    return 0;
}
*/
