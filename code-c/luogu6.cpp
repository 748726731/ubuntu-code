#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;cin>>n;
   string a;
   cin>>a;
   int a_cnt=0,b_cnt=0;
   for(int i=0;i<n-1;i++)//找几组VK
   {
      if(a[i]='V')
      {
         if(a[i+1]=='K')a_cnt++;   
      }
   }
   for(int i=0;i<n;i++)
   {
      string b=a;
      if(b[i]=='V')b[i]='K';
      else{b[i]='V';}
      for(int j=0;j<n-1;j++)//找几组VK
      {
         if(b[j]='V')
         {
            if(b[j+1]=='K')b_cnt++;   
         }
      }
      if(b_cnt>a_cnt)a_cnt=b_cnt;
      b_cnt=0;
   }
   cout<<a_cnt;
}