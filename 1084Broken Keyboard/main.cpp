//Broken Keyboard (20)
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
/*
On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters corresponding to those keys will not appear on screen.

Now given a string that you are supposed to type, and the string that you actually type out, please list those keys which are for sure worn out.

Input Specification:

Each input file contains one test case. For each case, the 1st line contains the original string, and the 2nd line contains the typed-out string. Each string contains no more than 80 characters which are either English letters [A-Z] (case insensitive), digital numbers [0-9], or "_" (representing the space). It is guaranteed that both strings are non-empty.

Output Specification:

For each test case, print in one line the keys that are worn out, in the order of being detected. The English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed that there is at least one worn out key.

Sample Input:
7_This_is_a_test
_hs_s_a_es
Sample Output:
7TI
*/

void Change(char ans[],int k,char *out,int &m)
{
  int i,j,flag = 1;
  for(i = 0; i < k; i++)
  {
    flag = 1;
    for(j = 0; j < i; j++)
    {
      if(toupper(ans[i]) == toupper(ans[j]))
        flag = 0;//如果遇到前面有相同的元素，则开始去重
    }
    if(flag)//如果前面没有重复的元素,放进新数组
    {
      out[m++] = toupper(ans[i]);
    }
  }
  out[m] = '\0';
}



int main()
{
  char str1[80];
  char str2[80];
  char ans[80];
  char out1[80],out2[80];
  gets(str1);
  gets(str2);
  int i = 0,j = 0,len1,len2,k = 0,m1 = 0,m2 = 0;
  int flag = 1;
  len1 = strlen(str1);
  len2 = strlen(str2);
  Change(str1,len1,out1,m1);
  Change(str2,len2,out2,m2);
  while(i < m1 && j < m2)
  {
    if(out1[i] == out2[j])
    {
      i++;
      j++;
    }
    else
    {
      ans[k++] = out1[i];
      i++;
    }
  }
  while(i < len1)
  {
    ans[k++] = out1[i];
    i++;
  }
  ans[k] = '\0';
  puts(ans);
  return 0;
}
