#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int>s;
    int n;
    cin>>n;
    string import;
    for(int i=0;i<n;i++)
    {
        cin>>import;
        if(import=="push")
        {
            int import1;//import,export/outport
            cin>>import1;
            s.push(import1);
        }
        if(import=="size")
        {
            cout<<s.size()<<"\n";
        }
        if(import=="query")
        {
            if(s.empty())
            {
                cout<<"Empty"<<"\n";
            }
            else 
            {
            cout<<s.top()<<"\n";//输出顶层
            }
        }
        if(import=="pop")
        {
            if(s.empty())//s.empty() 输出为bool，1=真 0=假
            {
                cout<<"Empty"<<"\n";
            }
            else 
            {
            s.pop();//remove
            }
        }
    }
}