#include<bits/stdc++.h>
using namespace std;
int main()
{
   string s;cin>>s;
   int cnt_math=0;
   int cnt_1=0,cnt_2=0;
   string output;
   for(int i=0;i<s.size();i++)
   {
      if(a[i]=='.'){cnt_math=1;cnt_1=i;}
      if(a[i]=='/'){cnt_math=2;cnt_2=i}
      if(a[i]=='%')cnt_math=3;
   }
   if(cnt_math==0);
   {
      output=reverse(s.begin(),s.end());
      while(output[0]=='0')
      {
         output.erase(output.begin());
      }
      cout<<output;
   }
      if(cnt_math==1);
   {
      string output_10,output_11;
      

   }
}