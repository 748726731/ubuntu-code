#include <bits/stdc++.h>
using namespace std;

int main() {
    int cnt;
    cin>>cnt;
    stack<string>b;
    for(int p=0;p<cnt;p++)
    {
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='o')
        {
            if(b.empty()||b.top()=="O")
            {
                b.push("o");
            }
            else if(b.top()=="o")
            {
                b.pop();
                if(b.empty()!=1&&b.top()=="O")
                {
                    b.pop();
                }
                else{b.push("O");}
            }
       
        }
            if(a[i]=='O')
        {
            if(b.empty()||b.top()=="o")
            {
                b.push("O");
            }
            else if(b.top()=="O")
            {
                b.pop();
            }
        
        }
    }
    string outport;
    while(b.empty()!=1)
    {
        outport+=b.top();//输出模块，设一个字符串，把栈上的全部传给字符串
        //然后倒置字符串，最后输出
        b.pop();
    }
    reverse(outport.begin(),outport.end());
    cout<<outport<<"\n";
    }
    return 0;
}