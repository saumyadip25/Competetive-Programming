#include"bits/stdc++.h"
using namespace std ;

int Trie[33*300005][2],C[33*300005],A[300005],B[300005];
int ptr;

void add(int curr)
{
    int i,j,k;

    int node=0;
    for(i=29;i>=0;i--)
    {
    int bit=(curr&(1<<i))?1:0;

    if(!Trie[node][bit])
    Trie[node][bit]=++ptr;

    node=Trie[node][bit];
    C[node]++;
    }

}

int query(int curr)
{
    int i,j,k;

    int ans=0,node=0;

    for(i=29;i>=0;i--)
    {
    int bit=(curr&(1<<i))?1:0;

    if(C[Trie[node][bit]]>0)
    {
    C[Trie[node][bit]]--;
    node=Trie[node][bit];
    }
    else
    {
    ans|=(1<<i);
    node=Trie[node][1-bit];
    C[node]--;
    }
    }
    return ans;
}

int main()
{
    int N,i,j,k;

    scanf("%d",&N);

    for(i=1;i<=N;i++)
    scanf("%d",&A[i]);

    for(i=1;i<=N;i++)
    {
    scanf("%d",&B[i]);
    add(B[i]);
    }

    for(i=1;i<=N;i++)
    printf("%d ",query(A[i]));

    printf("\n");
    return 0;
}


// http://codeforces.com/contest/948/submission/36209566
