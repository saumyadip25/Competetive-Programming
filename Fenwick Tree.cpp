#include<bits/stdc++.h>
using namespace std ;

const int n = 1e6+5;

int BIT[1000], a[1000];

void update(int x, int delta)
{
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}

int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

int main()
{
     scanf(“%d”, &n);
     int i;
     for(i = 1; i <= n; i++)
     {
           scanf(“%d”, &a[i]);
           update(i, a[i]);
     }
     

	int L,R;

	cin>>L>>R;	

	cout<<query(R)-query(L-1)<<endl;

     return 0;
}


