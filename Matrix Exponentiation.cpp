#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define MOD 1000000007

ll X[4][4],Y[4][4],Z[4][4];

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

void multiply(ll P[][4],ll Q[][4])
{
	int i,j,k;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			Z[i][j]=0;
			
			for(k=0;k<3;k++)
			{
				Z[i][j]=(Z[i][j]+P[i][k]*Q[k][j]%MOD)%MOD;
			}
		}
	}
	
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	P[i][j]=Z[i][j];
	
}

void expo(ll N)
{
	if(N<=1)
	return ;
	expo(N/2);
	multiply(X,X);
	if(N%2)
	multiply(X,Y);
}
int main()
{
	int T,i,j,k;
	
	ll N;
	
	scanf("%d",&T);
	while(T--)
	{
	scanf("%lld",&N);
	
	if(N==1 || N==2)
	{
	printf("0\n");
	continue;	
	}	
	if(N==3)
	{
		printf("1\n");
		continue;
	}
	
	X[0][0]=Y[0][0]=1;
	X[0][1]=Y[0][1]=1;
	X[0][2]=Y[0][2]=0;
	X[1][0]=Y[1][0]=1;
	X[1][1]=Y[1][1]=0;
	X[1][2]=Y[1][2]=1;
	X[2][0]=Y[2][0]=1;
	X[2][1]=Y[2][1]=0;
	X[2][2]=Y[2][2]=0;
	
	expo(N-2);
	
	ll ans=((X[0][0]*4LL)%MOD+(X[1][0]*2LL)%MOD+X[2][0]%MOD)%MOD;
	
	ll ff=fastpow(2,N);
	
	ll f=(ff-ans+MOD)%MOD;
	printf("%lld\n",f);
	}
	return 0;
}


https://www.codechef.com/viewsolution/14417638

