#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    vector<int> a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    string result;
       for(int i=0;i<(int)a.size();i++)
       {
        result=result+to_string(a[i]);
        if(i<(int)a.size()-1)
        result.insert(result.end(),',');//insert不仅可以用在vector，也可以用在string字符串里。
        //insert给第一个参数的前面 插入一个 第二个参数;
       }
       cout<<result<<"\n";
       return 0;
    }