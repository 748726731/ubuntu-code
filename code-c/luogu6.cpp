#include<bits/stdc++.h>
using namespace std;
int main()
{
   string s;cin>>s;
   int cnt_math=0;
   int cnt_1=0,cnt_2=0;
   for(int i=0;i<s.size();i++)
   {
      if(s[i]=='.'){cnt_math=1;cnt_1=i;}
      if(s[i]=='/'){cnt_math=2;cnt_2=i;}
      if(s[i]=='%')cnt_math=3;
   }
   if(cnt_math==0)
   {
      string output;
      output=s;
      reverse(output.begin(),output.end());//reverse 返回值是void.
      while(output.size()>1&&output[0]=='0')
      {
         output.erase(output.begin());
      }
      cout<<output;
   }
      if(cnt_math==1)
   {
      string output_10,output_11;
      output_10=s.substr(0,cnt_1);//截取:从s的0开始，往前走cnt_1步,
      output_11=s.substr(cnt_1+1);
      reverse(output_10.begin(),output_10.end());
      reverse(output_11.begin(),output_11.end());
      while(output_10.size()>1&&output_10[0]=='0')
      {
         output_10.erase(output_10.begin());//string的pop_front
      }
      while(output_11.size()>1&&output_11.back()=='0')
      {
         output_11.pop_back();
      }
      cout<<output_10<<"."<<output_11;
   }
      if(cnt_math==2)
   {
      string output_20,output_21;
      output_20=s.substr(0,cnt_2);
      reverse(output_20.begin(),output_20.end());//[)
      output_21=s.substr(cnt_2+1);
      reverse(output_21.begin(),output_21.end());
      while(output_20.size()>1&&output_20[0]=='0')
      {
         output_20.erase(output_20.begin());
      }
      while(output_21.size()>1&&output_21[0]=='0')
      {
         output_21.erase(output_21.begin());
      }
      cout<<output_20<<"/"<<output_21;
   }
   if(cnt_math==3)
   {
      string output;
      output=s;
      reverse(output.begin(),output.end()-1);

      while(output.size()>2&&output[0]=='0')
      {
         output.erase(output.begin());
      }
      cout<<output;
   }
}