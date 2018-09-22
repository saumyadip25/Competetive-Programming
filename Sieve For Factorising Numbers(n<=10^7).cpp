#include"bits/stdc++.h"
using namespace std;

int A[100005],dp[10000005],prime[10000005];
int a[1000005];

void sieve()
{
	int i,j,k;
	
	prime[1]=1;
	
	for(i=2;i<=10000000;i++)
	{
		if(!prime[i])
		for(j=i;j<=10000000;j+=i)
		if(!prime[j])
		prime[j]=i;
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	sieve();
	int T,N,i,j,k;
	cin>> T;
	
	while(T--)
	{
		cin>> N;
		
		for(i=1;i<=10000000;i++)
		dp[i]=0;
		
		for(i=1;i<=N;i++)
		cin>> A[i];
		
		int final =0;
		for(i=1;i<=N;i++)
		{
			
		int x=A[i];
		int y;
		vector <int> V;
		int ans=0;
		int k=0;
		while(x>1)
		{
			y=x;
			while(x%prime[y]==0)
			x/=prime[y];
			
			a[++k]=prime[y];
			ans=max(ans,dp[prime[y]]);
		}
			for(j=1;j<=k;j++)
			{
				dp[a[j]]=ans+1;
			}
			final=max(ans+1,final);
		}	
	    
		cout<<final<<"\n";
	}
	return 0;
}

// https://www.codechef.com/viewsolution/13144883
