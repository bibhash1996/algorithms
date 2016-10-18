#include<iostream>
using namespace std;
int main()
{
string pattern;
cin>>pattern;
int l=pattern.length();
//cout<<l;
int a[l],index=0;
a[0]=0;
for(int i=1; i < pattern.length();)
{
            if(pattern[i] == pattern[index])
            {
                a[i] = index + 1;
                index++;
                i++;
            }
            else
            {
                if(index != 0)
                {
                    index = a[index-1];
                }
                else
                {
                    a[i] =0;
                    i++;
                }
            }
}
for(int i=0;i<l;i++)
cout<<a[i]<<" ";
}
