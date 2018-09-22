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


int main()
{

    return 0;
}
