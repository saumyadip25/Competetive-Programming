#include"bits/stdc++.h"
using namespace std;
 
typedef long long ll;
#define inf 100000000000000LL
 
ll D[1000005];
 
vector< vector< pair<int, int> > > adj(100006);
priority_queue<pair<ll, int> ,vector< pair<ll, int> > ,greater< pair<ll, int> > > Q;
 
void relax(int u, int v, ll w)
{
	if(D[v]>D[u]+w)
	{
		D[v] = D[u] + w;
		Q.push(pair<ll, int>(D[v], v));
	}
}
 
 
void fun(int S)
{
	D[S]=0;
	
	Q.push(pair<ll, int>(D[S], S));
	
	while(!Q.empty())
	{
		pair<ll, int>x = Q.top();
		ll indx = x.second, dist = x.first;
		
		Q.pop();
		
		if(dist<=D[indx])
		{
			for(vector< pair<int,int> >::iterator it=adj[indx].begin(); it!=adj[indx].end(); it++)
				relax(indx, it->first, it->second);
		}
	}
	
}
 
 
int main()
{
int T,N,M,X,S,K,i,j,k;
	
	cin>>T;
	while(T--)
	{
	cin>>N>>K>>X>>M>>S;	
	
	for (i=1;i<=100005;i++)
	adj[i].clear();
	
	for(i=1;i<=M;i++)
		{
			int x,y,w;
			cin>>x>>y>>w;
			adj[x].push_back({y,w});
			adj[y].push_back({x,w});
		}
	
	if(S<=K)
	{
		for(i=1;i<=K;i++)
		{
			if(i==S)
			continue;
			adj[S].push_back({i,X});
			adj[i].push_back({S,X});
		}
	}
	else 
	{
		for(i=1;i<=N;i++)
		{
			D[i]=inf;
		}
		
		fun(S);
		
		ll mini=2*inf;
		int ind;
		for(i=1;i<=N;i++)
		{
			if(i<=K && D[i]<mini)
			{
				mini=D[i];
				ind = i;
			}
		}
		
		for(i=1;i<=K;i++)
		{
			if(i==ind)
			continue;
			adj[ind].push_back({i,X});
			adj[i].push_back({ind,X});
		}
	}
	
	for(i=1;i<=N;i++)
	D[i]=inf;
	
	fun(S);
	
	for(i=1;i<=N;i++)
	cout<<D[i]<<" ";
	
	cout<<"\n";	
}
	return 0;
}   


// https://www.codechef.com/viewsolution/13303482




