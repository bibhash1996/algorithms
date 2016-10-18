//Bibhash Singh

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bit[100000];
int n;
int equal_or_not(ll x)
{      
    if(x==0)return 1;
    int rem=x%10;
    int dig;
    while(x>0)
    {
	dig=x%10;
	x/=10;
    }
    if(dig==rem)
	return 1;
    return 0;
}
void update(int idx,int val)
{
    while(idx<=n)
    {
	bit[idx]+=val;
	idx+=(idx&-idx);
    }
}

int query(int idx)
{
    int sum=0;
    while(idx>0)  
     {
	 sum+=bit[idx];
	 idx-=(idx&-idx);
    }
  return sum;  
}

int main()
{
    std::ios_base::sync_with_stdio(false);
   // string s;
    
    int q,x;
    ll a[100000];
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
	cin>>a[i];
	update(i,equal_or_not(a[i]));
    }
    while(q--)
    {
    int type;
    cin>>type;
    if(type==1)
    {
	int l,r;
	cin>>l>>r;
	cout<<query(r)-query(l-1)<<endl;
    }
    else
    {
       int i;
       cin>>i>>x;
       update(i,-equal_or_not(a[i]));
       a[i]=x;
       update(i,equal_or_not(a[i]));
    }
    
    }
}