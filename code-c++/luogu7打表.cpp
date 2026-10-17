#include<bits/stdc++.h>
using namespace std;
int f(int x, const vector<int> &zhishu)
{
   for(int i=0;i<(int)zhishu.size();i++)
   {
    if(zhishu[i] > x/2) break;
    int cnt = x - zhishu[i];
    for(int j=i;j<(int)zhishu.size();j++)
    {
        if(cnt == zhishu[j]) return cnt;
    }
   }
   return -1;
}
int main()
{
    int n;cin>>n;int a,b;

    vector<int> zhishu;                    //建表
    for(int i=2;i<=n;i++)
    {
        int check=1;
        for(int j=2;j*j<=i;j++)
            if(i%j==0){check=0;break;}
        if(check==1)zhishu.push_back(i);
    }

    for(int i=4;i<=n;i=i+2)
    {
        a=f(i,zhishu);b=i-a;
        cout<<i<<"="<<b<<"+"<<a<<endl;
    }
}