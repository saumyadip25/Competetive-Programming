#include"bits/stdc++.h"
using namespace std ;
typedef long long ll;
#define inf 100000000000000LL;

ll dpL[2005][2005],dpR[2005][2005];
int dx[4]={0, 0, +1, -1};
int dy[4]={+1, -1, 0, 0};
ll costl[4]={0, 1, 0, 0};
ll costr[4]={1, 0, 0, 0};
char S[2006][2006];
deque < pair<int,int> > Q;
int N,M;

bool valid(int x,int y)
{
    return (x>=1 && x<=N && y>=1 && y<=M && (S[x][y]=='.'));
}

int main()
{
    int R,C,X,Y,i,j,k;

    cin>>N>>M;
    cin>>R>>C;
    cin>>X>>Y;

    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
            cin>>S[i][j];

    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
            dpL[i][j]=dpR[i][j]=inf;

    dpL[R][C]=0;

    Q.push_front({R,C});

    while(!Q.empty())
    {
        pair <int,int> p = Q.front();
        Q.pop_front();

        int x=p.first;
        int y=p.second;

        for(k=0;k<4;k++)
        {
            int xx=x+dx[k];
            int yy=y+dy[k];

            if(valid(xx,yy) && dpL[xx][yy]>costl[k]+dpL[x][y])
            {
                dpL[xx][yy]=costl[k]+dpL[x][y];
                if(costl[k])
                Q.push_back({xx,yy});
                else
                Q.push_front({xx,yy});
            }
        }

    }

    dpR[R][C]=0;
    Q.push_front({R,C});

    while(!Q.empty())
    {
        pair <int,int> p = Q.front();
        Q.pop_front();

        int x=p.first;
        int y=p.second;

        for(k=0;k<4;k++)
        {
            int xx=x+dx[k];
            int yy=y+dy[k];

            if(valid(xx,yy) && dpR[xx][yy]>costr[k]+dpR[x][y])
            {
                dpR[xx][yy]=costr[k]+dpR[x][y];
                if(costr[k])
                Q.push_back({xx,yy});
                else
                Q.push_front({xx,yy});
            }
        }

    }

    int ans = 0;

    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
            ans+=(dpL[i][j]<=X && dpR[i][j]<=Y);

    cout<<ans<<endl;
    return 0;
}

// https://codeforces.com/contest/1064/submission/44817691
