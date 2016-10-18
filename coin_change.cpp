#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int find_min(int n,int count1[])
{
   if(n==0)
   return 0;

   if(n < 0)
   return INT_MAX-5;

   if(count1[n]!=-1)
   return count1[n];

     int x=1+find_min(n-1,count1);
     int y=1+find_min(n-3,count1);
     int z=1+find_min(n-5,count1);
     int a=min(x,y);
     // return count1[n]=min(a,z);
     return count1[n]=min(a,z);

}
int main()
{
cout<<"enter";
int n;
cin>>n;
int count1[1000];
for(int i=0;i<n+1;i++)
count1[i]=-1;
int x=find_min(n,count1);
cout<<x<<endl;
}
