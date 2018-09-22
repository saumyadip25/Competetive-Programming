#include<bits/stdc++.h>
using namespace std;

int pr[1000006];
// Finding prime in range L to R when R-L<=10^6 and R<=10^12
void prime(long long int m,long long int n)
{
	for(long long int i = 2;i*i <= n;i++)
	{
		for(long long int j = max(i*i,((m+(i-1))/i)*i ); j <=n ; j+=i)
		{	
		//	cout<<i<< " "<< " "<<j<<" ";
		    pr[j-m]=0;
		    
		}
		//cout<<"\n";
	}
 
}
 
void solve(long long int m,long long int n)
{
	prime(m,n);
	for(long long i = max(2LL,m); i<=n;i++)
	{
		if(pr[i-m])
			printf("%lld\n",i);
	}
}
 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    for(int i =0;i<1000001;i++)
	    pr[i] = 1;
	        
		long long int n,m;
		scanf("%lld%lld",&m,&n);
		m = max((long long int )2,m);
		solve(m,n);
	    printf("\n");
	}
	return 0;
} 


// https://www.codechef.com/viewsolution/13422642   ------> PRIME1
// https://www.codechef.com/viewsolution/13327747   ------> PRETNUM (Finding number of divisors of all the numbers)
// https://www.codechef.com/viewsolution/13322020   ------> CHEFDIV (Factorising all the the numbers in the range)
