#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;//循环次数
    vector<int>p;//序列
    stack<int>l;//栈
    for(int i=0;i<n;i++)
    {
        int k;cin>>k;
        p.push_back(k);
    }//把数据存进序列里
   
    //查最大值，从序列i=0开始到i=n-1时，运行到每个数时的最大值.
    vector<int>biggest(n+1,0);
    //要倒着走，例如91257,最大值表分别是 97777
    for(int i=n-1;i>=0;i--){biggest[i]=biggest[i+1];
    if(p[i]>biggest[i]){biggest[i]=p[i];}}

    int i=0;
    while(i<n||l.empty()==0)
    {
        int max=biggest[i];
        if(l.empty()==0&&l.top()>max){cout<<l.top()<<" ";l.pop();}
        else{l.push(p[i]);i++;}
    }
    return 0;
}