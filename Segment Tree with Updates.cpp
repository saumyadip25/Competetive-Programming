#include"bits/stdc++.h"
using namespace std ;

void build(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
   
        build(2*node, start, mid);
        
        build(2*node+1, mid+1, end);
        
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        A[idx] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;

        if(start <= idx and idx <= mid)
        {
            
            update(2*node, start, mid, idx, val);
        }
        else
        {
            
            update(2*node+1, mid+1, end, idx, val);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

int query(int node, int start, int end, int L, int R)
{
    if(R < start or end < L)
    {
        return 0;
    }
    if(L <= start and end <= R)
    {
        return tree[node];
    }
    
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, L, R);
    int p2 = query(2*node+1, mid+1, end, L, R);
    return (p1 + p2);
}

int main()
{
	

	return 0;	
}
