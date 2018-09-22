#include"bits/stdc++.h"
using namespace std ;

int par[406],size[200];

string S1,S2;

vector < pair<char,char> > X;

int find_parent(int l)
{
    if(par[l]==l)
	return l;
    else
	find_parent(par[l]);
}

void unite(int a,int b)
{
     a=find_parent(a);
     b=find_parent(b);


    if(a==b)
    return ;

    if(size[a]>=size[b])
    {
        size[a]+=size[b];
        par[b]=a;
    }
    else
    {
        size[b]+=size[a];
        par[a]=b;

    }

}


int main()
{
    int N,i,j,k;
    
    
    cin>>N;
    
    cin>>S1>>S2;


    for(i=1;i<=30;i++)
    {
        par[i]=i;
        size[i]=1;
    }

    for(i=0;i<S1.size();i++)
    {
    int a=S1[i]-'a'+1;
    int b=S2[i]-'a'+1;

    int x=find_parent(a);
    int y=find_parent(b);

    if(x==y)
    continue;

    else
    {
    unite(a,b);
    X.push_back({S1[i],S2[i]});
    }

    }

    cout<<(int)X.size()<<"\n";

    for(i=0;i<X.size();i++)
    cout<<X[i].first<<" "<<X[i].second<<"\n";

    return 0;
}


// http://codeforces.com/contest/939/submission/35413393
