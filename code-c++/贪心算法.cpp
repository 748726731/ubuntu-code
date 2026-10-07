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
    int i=0;
    while(i<n||l.empty()==0)
    {
        int max=0;
        for(int j=i;j<n;j++){if(p[j]>max){max=p[j];}}
        //例如当序列第一个数丢进栈了以后
        //重新判断哪个数是最大值
        if(l.empty()==0&&l.top()>max){cout<<l.top()<<" ";l.pop();}
        //假如栈上的最大，就输出.
        else{l.push(p[i]);i++;}
    }
}