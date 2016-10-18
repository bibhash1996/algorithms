// Bibhash Singh -Kosaraju

#include<bits/stdc++.h>
using namespace std;

stack<int>st;
vector<int>v[100001],r[100001];
bool visited[100001],visited1[100001];
int length=0,n;

void dfs1(int x)
{
    visited[x]=true;
    for(int i=0;i<v[x].size();i++)
	if(!visited[v[x][i]])
	    dfs1(v[x][i]);
	
    st.push(x);
    return;
}

void dfs2(int x)
{
    visited1[x]=true;
    for(int i=0;i<r[x].size();i++)
	if(!visited1[r[x][i]])
	    dfs2(r[x][i]);
	
    length++;
    return;
}

int kosaraju()
{
    length=0;
    int sum=0;
    for(int i=0;i<n;i++)
	if(!visited[i])
	    dfs1(i);
    
    while(!st.empty())
    {
	int t=st.top();
	st.pop();
	 
	if(!visited1[t])
        {
	    dfs2(t);
	}    
	    if(length>1)
		sum++;
	    length=0;
	
    }	

  return sum;  
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int m;
      cin>>n>>m;
      for(int i=0;i<100001;i++)
      {
	visited[i]=false;
	visited1[i]=false;
      }
       while(m--)
            {
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		r[b].push_back(a);
	    }
	int x = kosaraju();
        cout<<x<<endl;
       for(int i=0;i<100001;i++)
       {
	v[i].clear();
	r[i].clear();
       }
       
    }
}