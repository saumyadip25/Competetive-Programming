#include"bits/stdc++.h"
using namespace std;

int tree[400005],lazy[400005];

void update(int node,int start,int end,int l,int r)
{
	if(lazy[node])
	{
		tree[node]=(end-start+1)-tree[node];
		if(start!=end)
		{
			lazy[2*node]=1-lazy[2*node];
			lazy[2*node+1]=1-lazy[2*node+1];
		}
		lazy[node]=0;
	}
	if(start>end || start>r || end<l)
	return ;
	
	if(start>=l && end<=r)
	{
		tree[node]=(end-start+1)-tree[node];
		
		if(start!=end)
		{
			lazy[2*node]=1-lazy[2*node];
			lazy[2*node+1]=1-lazy[2*node+1];
		}
		return ;
	}
	int mid=(start+end)/2;
	update(2*node,start,mid,l,r);
	update(2*node+1,mid+1,end,l,r);
	
	tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int node,int start,int end,int l,int r)
{
	if(start>end || l>end || start>r)
	return 0;
	
	if(lazy[node])
	{
		tree[node]=(end-start+1)-tree[node];
		
		if(start!=end)
		{
			lazy[2*node]=1-lazy[2*node];
			lazy[2*node+1]=1-lazy[2*node+1];
		}
		lazy[node]=0;
	}
	if(start>=l && end<=r)
	return tree[node];
	
	int mid=(start+end)/2;
	int p1=query(2*node,start,mid,l,r);
	int p2=query(2*node+1,mid+1,end,l,r);
	
	return p1+p2;
}

int main()
{
	int N,Q,i,j,k;
	
	cin>>N>>Q;
	
	int q,L,R;
	
	while(Q--)
	{
		cin>>q;
		if(q==0)
		{
		cin>>L>>R;
		update(1,0,N-1,L,R);
		}
		else 
		{
		cin>>L>>R;
		printf("%d\n",query(1,0,N-1,L,R));	
		}
	}

	return 0;
}


// https://www.codechef.com/viewsolution/14408967

