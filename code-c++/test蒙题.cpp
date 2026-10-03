#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;//得到题目数量 
   while(n>0)
   {
    n--;
    string s[4];//ABCD对应s[0]...s[3] 
    int len[4];//ABCD的字节数量 
    for(int i=0;i<=3;i++)
    {
    cin>>s[i];//输入ABCD 
    len[i]=s[i].size();//根据输入的东西得字节 
    }
    int minLen=len[0],maxLen=len[0];//最小字节数，最大字节数 
    for(int i=0;i<=3;i++)
    {
        minLen=min(minLen,len[i]);//得到ABCD最小字节数是多少
        maxLen=max(maxLen,len[i]);//最大字节数是多少
    }
    int minCnt=0,maxCnt=0,cntmin=0,cntmax=0;
    for(int i=0;i<=3;i++)
    {
       if(len[i]==minLen)//若ABCD的字节数等于最小字节数，min计数器+1 
       {
        minCnt++;
        cntmin=i;//记录当ABCD其中之一的字节数等于最小字节数时，与'A'(ASCII)差多少.
       }
       if(len[i]==maxLen)
       {
        maxCnt++;//同上 
        cntmax=i;
       }
    }
        if(minCnt==1&&maxCnt!=1)//由于题目要求，最小或最大字节数的选项只有一个,否则输出C。
        {
            cout<<char('A'+cntmin)<<"\n";
        }
        else if(maxCnt==1&&minCnt!=1)
        {
           cout<<char('A'+cntmax)<<"\n";
        }
        else
        {
            cout<<"C"<<"\n";
        }
   }        
    return 0;                                                          
}
