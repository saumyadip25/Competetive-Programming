#include"bits/stdc++.h"
using namespace std ;
#define MOD 1000000007

long long fastpow(long long base,long long exp)
{
	if(exp==0)
	return 1;
	if(exp==1)
	return base%MOD;
	long long midi=fastpow(base,exp/2);
	if(exp%2)
	{
		return ((midi*base)%MOD*midi)%MOD;
	}

	return (midi*midi)%MOD;
}

long long C[5005][5005];

int main()
{
	for(int i=0; i<=5000; i++)
		C[i][0] = 1;

	for(int i=1; i<=5000; i++)
		for(int j=1; j<=i; j++)
			C[i][j] = (C[i-1][j-1] + C[i-1][j]);
	
	
    return 0;
}
