//Segment Tree - Bibhash Singh

#include<bits/stdc++.h>
using namespace std;
long long tree[200001],a[100001];
void build(long long node,long long start,long long end)
{
     if(start == end)
     {
       tree[node]=a[start];
     }
     else
    {
      
        long long mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

void update(long long node,long long idx,long long val,long long start,long long end)
{
    if(start==end)
    {
        a[idx]=(val%2==0)?1:0;
        tree[node]=a[idx];
    }
    else
    {
        long long mid=(start+end)/2;
        if(idx>=start &&  idx <= mid)
            update(2*node,idx,val,start,mid);
        else
          update(2*node+1,idx,val,mid+1,end);
        
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

long long query(long long node,long long start,long long end,long long l,long long r)
{
   if(l> end || r<start)
       return 0;
   
   if(l<=start && r>=end)
       return tree[node];
   long long mid = (start+end)/2;
   long long x1=query(2*node,start,mid,l,r);
   long long x2=query(2*node+1,mid+1,end,l,r);
   return x1+x2;
}

int main()
{
    long long  n,i,x;
    cin>>n;
    for(i=1;i<=n;i++) 
      {
          cin>>x;
          a[i]=x%2==0 ? 1:0;
      }
     build(1,1,n);
    long long q;
    cin>>q;
    while(q--)
    {
     long long t,b,c;
     cin>>t>>b>>c;
     if(t==0)
     {
       update(1,b,c,1,n); 
     }
     else if(t==1)
     {
      cout<<query(1,1,n,b,c)<<endl;  
     }
     else
     {
      if(b==c)
          cout<<a[b]<<endl;
      else
          cout<<c-b+1-query(1,1,n,b,c)<<endl;
     }
    }
}