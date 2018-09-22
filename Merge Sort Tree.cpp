#include"bits/stdc++.h"
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MOD 1000000007
typedef long long ll;

vector <ll> tree[800006];
ll A[1000006],prefix[1000006];

vector <ll> join(vector <ll> a,vector <ll> b)
{
    vector <ll> c;
    int i,j,k,ptr1=0,ptr2=0;

    while(ptr1<a.size() || ptr2<b.size())
    {
        if(ptr1==a.size())
        {
            c.push_back(b[ptr2]);
            ptr2++;
        }
        else if(ptr2==b.size())
        {
            c.push_back(a[ptr1]);
            ptr1++;
        }
        else
        {
            if(a[ptr1]<=b[ptr2])
            {
                c.push_back(a[ptr1]);
                ptr1++;
            }
            else
            {
                c.push_back(b[ptr2]);
                ptr2++;
            }
        }
    }

    return c;
}

void build(int node,int start,int end)
{
    if(start==end)
    {
        tree[node].push_back(prefix[start]);
        return ;
    }

        int mid=(start+end)/2;

        build(2*node,start,mid);
        build(2*node+1,mid+1,end);

        tree[node]=join(tree[2*node],tree[2*node+1]);
}

ll query(int node,int start,int end,ll val,int L,int R)
{
    if(L>end || R<start)
        return 0;

    if(start>=L && end<=R)
    {

        int s=0,e=(int)tree[node].size()-1;
        ll ans=-1;
        while(s<=e)
        {
            int m=(s+e)/2;
            if(tree[node][m]<val)
            {
                ans=m;
                s=m+1;
            }
            else
            {
                e=m-1;
            }
        }
        ll up=ans+1;

        return up;
    }

    int mid=(start+end)/2;

    ll p1=query(2*node,start,mid,val,L,R);
    ll p2=query(2*node+1,mid+1,end,val,L,R);

    return p1+p2;
}

int main()
{
    fast;

    int N,i,j,k;
    ll t;

    cin>>N>>t;

    for(i=1;i<=N;i++)
    {
        cin>>A[i];
        prefix[i]=prefix[i-1]+A[i];
    }

    build(1,1,N);

    ll ans=0;
    ll now=0;
    prefix[0]=0;
    for(i=1;i<=N;i++)
    {
        ans+=query(1,1,N,t+prefix[i-1],i,N);
        //cout<<ans<<endl;
    }

    printf("%lld\n",ans);

    return 0;
}

// http://codeforces.com/contest/1042/submission/42998515
