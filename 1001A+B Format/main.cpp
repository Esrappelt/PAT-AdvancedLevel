#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include<sstream>
#include <stack>
#include <list>
#include <vector>
#include <malloc.h>
#include <memory.h>
using namespace std;
/*
Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input
-1000000 9
Sample Output
-999,991

*/
int main()
{
    int a,b,c;
    scanf("%d%d",&a,&b);
    c = a + b;
    if(c < 0)
    {
        printf("-");
        c = -c;
    }
    if( c < 1000 )
        printf("%d\n",c);
    else if(c >= 1000 && c < 1000000)
        printf("%d,%03d\n",c/1000,c%1000);
    else if(c >= 1000000)
        printf("%d,%03d,%03d\n",c/1000000,(c/1000)%1000,c%1000);
	return 0;
}
