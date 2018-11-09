#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define Maxsize 999999


vector<long> p(Maxsize);
vector<long> prime(Maxsize);
long top;

struct node
{
    int k;
    long data;
};
vector<node> ans;

void FindPrime(long n)
{
    long i,j;
    for(i = 2; i <= n; i++)
    {
        if(p[i] == 0)
            prime[top++] = i;
        for(j = 0; j < top && i * prime[j] <= n; j++)
        {
            p[i * prime[j]] = 1;
            if(i % prime[j] == 0)
                break;
        }
    }
}


void solve(long n)
{
    node tmp;
    int t = (int)sqrt(n);
    for(int i = 0; i < top && prime[i] <= t; ++i)
    {
        int k = 0;
        if(n % prime[i] == 0)
        {
            while(n % prime[i] == 0)
            {
                k++;
                n /= prime[i];
            }
            tmp.data = prime[i];
            tmp.k = k;
            ans.push_back(tmp);
        }
    }
    if(n > 1)
    {
        tmp.data = n;
        tmp.k = 1;
        ans.push_back(tmp);
    }
    for(unsigned int i = 0; i < ans.size(); ++i)
    {
        if(ans[i].k)
            ans[i].k == 1 ? printf("%ld",ans[i].data): printf("%ld^%d",ans[i].data,ans[i].k);
        else
            printf("%ld",ans[i].data);
        if(i < ans.size() - 1)
            cout << '*';
    }
}
int main()
{
    long n;
    scanf("%ld", &n);
    FindPrime(10000);
    printf("%ld=",n);
    if(n == 1)
        printf("1");
    solve(n);
    return 0;
}
/*
Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p1^k1 * p2^k2 *бн*pm^km.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range of long int.

Output Specification:

Factor N in the format N = p1^k1 * p2^k2 *бн*pm^km, where pi's are prime factors of N in increasing order, and the exponent ki is the number of pi -- hence when there is only one pi, ki is 1 and must NOT be printed out.

Sample Input:
97532468
Sample Output:
97532468=2^2*11*17*101*1291
*/
