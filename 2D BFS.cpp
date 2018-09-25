#include"bits/stdc++.h"
using namespace std ;

int N,M,K;
int dis[1005][1005][5];
char S[1005][1005];

queue < pair<int,int> > Q; 


bool valid(int x,int y,int type)
{
	if(x>=0 && x<N && y>=0 && y<M && S[x][y]=='.' && dis[x][y][type]==-1)
	return true;
	
	return false;
}

void bfs(int x1,int y1)
{
	Q.push({x1,y1});
	
	for(int i=0;i<4;i++)
	dis[x1][y1][i]=0;
	
	while(!Q.empty())
	{
		pair <int,int> p=Q.front();
		
		int x=p.first;
		int y=p.second;
		
		Q.pop();
		
		int mini=1e9;
		
		for(int i=0;i<4;i++)
		{
		if(dis[x][y][i]!=-1)
		mini=min(mini,dis[x][y][i]);
		}
		
		for(int i=1;i<=K;i++)
		{
			if(valid(x+i,y,0))
			{
				Q.push({x+i,y});
				dis[x+i][y][0]=mini+1;
			}
			else 
			break;
		}
		
		for(int i=1;i<=K;i++)
		{
			if(valid(x-i,y,1))
			{
				Q.push({x-i,y});
				dis[x-i][y][1]=mini+1;
			}
			else 
			break;
		}
		
		for(int i=1;i<=K;i++)
		{
			if(valid(x,y+i,2))
			{
				Q.push({x,y+i});
				dis[x][y+i][2]=mini+1;
			}
			else 
			break;
		}
		
		for(int i=1;i<=K;i++)
		{
			if(valid(x,y-i,3))
			{
				Q.push({x,y-i});
				dis[x][y-i][3]=mini+1;
			}
			else 
			break;
		}
		
	}
	
}

int main()
{
	int i,j,k;
	
	cin>>N>>M>>K;
	
	for(i=0;i<N;i++)
	for(j=0;j<M;j++)
	cin>>S[i][j];
	
	int x1,x2,y1,y2;
	
	cin>>x1>>y1>>x2>>y2;
	
	x1--;
	y1--;
	x2--;
	y2--;
	
	for(i=0;i<1005;i++)
	for(j=0;j<1005;j++)
	for(k=0;k<5;k++)
	dis[i][j][k]=-1;
	
	bfs(x1,y1);
	
	int minn=1e9;
	
	for(i=0;i<4;i++)
	{
		if(dis[x2][y2][i]!=-1)
		minn=min(minn,dis[x2][y2][i]);
	}
	
	if(minn==1e9)
	printf("-1\n");
	else 
	printf("%d\n",minn);
	return 0;
}


// http://codeforces.com/contest/877/submission/31956300

