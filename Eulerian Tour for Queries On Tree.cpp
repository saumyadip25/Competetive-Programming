#include<bits/stdc++.h>
using namespace std ;


// for doing range related queries in tree
void dfs(int node,int par)
{
    tin[node]=++timer;
    rev[timer]=node;
    for(int i=0;i<adj[node].size();i++)
    {
    if(adj[node][i]==par)
    continue;
    dfs(adj[node][i],node);
    }
    tout[node]=timer;
}

// for path queries in trees
void dfs(int node,int par,int level)
{
	tin[node]=++timer;
	lvl[node]=level;
	
	for(int i=0;i<adj[node].size();i++)
	{
		if(adj[node][i].first==par)
		continue;
		
		dfs(adj[node][i].first,node,level+1);
	}
	tout[node]=++timer;
}

// https://codeforces.com/blog/entry/43230 

int main()
{

return 0;
}
