//Bibhash Singh - fast gcd

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b)
{
    if(a == b)
	return a;
    if(a == 0)
	return b;
    if(b == 0)
	return a;
    
    if(~a & 1)
    {
	if(b & 1)
	  return gcd( a>>1,b);
	else
	  return gcd(a>>1,b>>1) <<1;
    }
    
    if(~b & 1)
	return gcd(a,b>>1);
    if(a>b)
	return gcd((a-b)>>1,b);
    return gcd((b-a)>>1,a);
}

int main()
{
    ll a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
}