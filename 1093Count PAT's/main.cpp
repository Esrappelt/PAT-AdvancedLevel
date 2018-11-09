#include <string>
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int nump = 0,numa = 0,numt = 0;
	string a;
	cin >> a;
	for(int i = a.length() - 1; i >= 0; --i)
	{
		if(a[i] == 'T') numt = (numt + 1) % 1000000007;
		else if(a[i] == 'A') numa = (numt + numa) % 1000000007;
		else nump = (nump + numa) % 1000000007;
	}
	printf("%d\n",nump);
	return 0;
}

