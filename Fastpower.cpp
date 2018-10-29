#include"bits/stdc++.h"
using namespace std ;
#define MOD 1000000007

long long fastpow(long long base,long long exp)
{
	if(exp==0)
	return 1;
	if(exp==1)
	return base%MOD;
	long long midi=fastpow(base,exp/2);
	if(exp%2)
	{
		return ((midi*base)%MOD*midi)%MOD;
	}

	return (midi*midi)%MOD;
}

long long C[5005][5005];

int main()
{
	for(int i=0; i<=5000; i++)
		C[i][0] = 1;

	for(int i=1; i<=5000; i++)
		for(int j=1; j<=i; j++)
			C[i][j] = (C[i-1][j-1] + C[i-1][j]);
	
	
    return 0;
}

/*
syntax for policy based DSA;

#include"bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main() 
{ 
    new_data_set p; 
    p.insert(5); 
    p.insert(2); 
    p.insert(6); 
    p.insert(4); 
  
    // value at 3rd index in sorted array. 
    cout << "The value at 3rd index ::" 
         << *p.find_by_order(3) << endl; 
  
    // index of number 6 
    cout << "The index of number 6::" 
         << p.order_of_key(6) << endl; 
  
    // number 7 not in the set but it will show the  
    // index number if it was there in sorted array. 
    cout << "The index of number seven ::"
         << p.order_of_key(7) << endl; 
  
    return 0; 
} 

*/
