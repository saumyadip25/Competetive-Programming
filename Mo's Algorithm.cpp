#include"bits/stdc++.h"
using namespace std ;

struct node{
    int L,R,K;
    int idx;
} query[200005];

int BLOCK;

bool compare(node x,node y)
{
    if(x.L/BLOCK!=y.L/BLOCK)
    return x.L/BLOCK<y.L/BLOCK;

    return x.R<y.R;
}

int A[200005],f[200005],B[200005],ans[200005],rev[200005];

void add(int x)
{
    f[B[x]]++;
    rev[f[B[x]]]++;
}

void remove(int x)
{
    rev[f[B[x]]]--;
    f[B[x]]--;
}

int main()
{
    int T,N,i,j,k,Q;

    cin>>T;

    while(T--)
    {

    for(i=0;i<200005;i++)
    {
    f[i]=0;
    query[i].L=0;
    query[i].R=0;
    query[i].K=0;
    query[i].idx=0;
    B[i]=0,rev[i]=0;
    ans[i]=0;
    }

    cin>>N>>Q;

    BLOCK=sqrt(N);

    for(i=1;i<=N;i++)
    cin>>A[i];

    B[1]=1;
    k=1;
    for(i=2;i<=N;i++)
    {
    if(A[i]==A[i-1])
    B[i]=B[i-1];
    else
    {
    B[i]=++k;
    }
    }

    for(i=1;i<=Q;i++)
    {
    int L,R,K;

    cin>>L>>R>>K;

    query[i].L=L;
    query[i].R=R;
    query[i].K=K;
    query[i].idx=i;
    }

    sort(query+1,query+Q+1,compare);

    int left=query[1].L;
    int right=query[1].L-1;

    for(i=1;i<=Q;i++)
    {
        int L=query[i].L;
        int R=query[i].R;
        int K=query[i].K;
        int indx=query[i].idx;

        while(left<L)
        {
            remove(left);
            left++;
        }

        while(left>L)
        {
            left--;
            add(left);
        }

        while(right<R)
        {
            right++;
            add(right);
        }

        while(right>R)
        {
            remove(right);
            right--;
        }

        ans[indx]=rev[K];
    }

    for(i=1;i<=Q;i++)
    cout<<ans[i]<<"\n";

    }

    return 0;
}

// https://www.codechef.com/viewsolution/17955440
