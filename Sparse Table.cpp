#include"bits/stdc++.h"
using namespace std ;

int SP[25][1000006];
int A[1000006],D[1000006];

int query(int L,int R)
{
    if(L == R)
        return A[L];

    int d = D[R - L + 1]; // helps to answer queries in O(1)

    return min(SP[d][L] , SP[d][R-(1<<d)+1]);

}

int main()
{
    int N,i,j,k;

    for(i=2;i<=1000000;i++)
    D[i]=D[i/2]+1;

    cin>>N;

    for(i=1;i<=N;i++)
    cin>>A[i];

    for(i=1;i<=N;i++)
    {
        SP[0][i]=A[i];
    }

    for(i=1; i<25; i++)
    {
    for(j=1; j + (1 << (i-1)) <= N; j++)
    {
    SP[i][j] = min(SP[i-1][j] , SP[i-1][j + (1 << (i-1))]);
    }
    }

    int Q;

    cin>>Q;

   while(Q--)
   {
       int L,R;

       cin>>L>>R;

       printf("%d\n",query(L,R));

   }

    return 0;
}

