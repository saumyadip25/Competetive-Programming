#include"bits/stdc++.h"
using namespace std ;

list <int> Q;
unordered_map<int, list<int>::iterator> mp;

int F=4;

void Add(int x)
{
	if(mp.find(x)!=mp.end())
	{
			Q.erase(mp[x]);
			mp.erase(x);
			Q.push_front(x);
			mp[x]=Q.begin();		
	}
	else 
	{
		if(mp.size()==F)
		{
			int last = Q.back();
			Q.pop_back();
			mp.erase(last);
			Q.push_front(x);
			mp[x]=Q.begin();
		}
		else 
		{
			Q.push_front(x);
			mp[x]=Q.begin();
		}
	}
}


int main()
{
	int N,i,j,k;
	
	
	
	while(1)	
	{
		int x,type;
		cout<<"\n 1 Add 2 Display 3 Stop\n";
		cin>>type;
		if(type==1)
		{
			cin>>x;
			Add(x);
		}
		else if(type==2)
		{
			for(auto it:Q)
			cout<<it<<" ";
		}
		else
		{
			break;
		}
	} 
	
	
	return 0;
}
