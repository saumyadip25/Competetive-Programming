#include"bits/stdc++.h"
using namespace std ;
typedef long long ll;
#define MOD 1000000007

ll prefix[400005],sufix[400005],Power[400005];
ll p = 31LL;

ll get(char s)
{
    ll ans = s-'a';
    return ans;
}

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
    int T,N,i,j,k,n;

    cin>>T;

    while(T--)
    {

    for(i=0;i<400005;i++)
    {
    prefix[i]=0;
    sufix[i]=0;
    Power[i]=0;
    }

    string S;

    cin>>S;

    N=S.size();

    S=S+S;

    n=S.size();

    Power[0]=1LL;

    for(i=1;i<=n;i++)
    Power[i]=(Power[i-1]*p)%MOD;

    prefix[0]=(get(S[0])*Power[0])%MOD;

    for(i=1;i<n;i++)
    prefix[i] = (prefix[i-1]%MOD + (get(S[i])*Power[i])%MOD)%MOD;

    sufix[n-1] = (Power[0]*get(S[n-1]))%MOD;
    int ptr=1;

    int ans = 0;

    for(i=n-2;i>=0;i--)
    {
    sufix[i] = (sufix[i+1]%MOD + (get(S[i])*Power[ptr])%MOD)%MOD;
    ptr++;
    }

    ptr = N;

    for(i=0;i<N;i++)
    {
    int pL = i;
    int pR = i+N-1;

    ll p1 ;

    if(pL==0)
    p1 = (prefix[pR]-prefix[pL]+MOD)%MOD;
    else
    p1 = (prefix[pR]-prefix[pL-1]+MOD)%MOD;

    ll rem = Power[i];
    ll inv = fastpow(rem,MOD-2);
    p1 = (p1*inv)%MOD;

    int bL = i+N;
    int bR = i;

    ll p2 ;
    p2 = (sufix[bR]-sufix[bL]+MOD)%MOD;
    rem = Power[ptr];
    inv = fastpow(rem,MOD-2);
    p2 = (p2*inv)%MOD;

    if(p1==p2)
    ans++;

    ptr--;
    }

    printf("%d\n",ans);

    }

    return 0;
}


// https://www.codechef.com/viewsolution/18672486

