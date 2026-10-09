#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    queue<int>myqueue;
    for(int i=0;i<n;i++)
    {
        int a=0;cin>>a;
        if(a==1){int a1;cin>>a1;myqueue.push(a1);}
        if(a==2){if(myqueue.empty()==0){myqueue.pop();}
        else{cout<<"ERR_CANNOT_POP"<<"\n";}}
        if(a==3){if(myqueue.empty()==0){cout<<myqueue.front()<<"\n";}
        //and myqueue.back() to get the last element of the queue
        else{cout<<"ERR_CANNOT_QUERY"<<"\n";}}
        if(a==4){cout<<myqueue.size()<<"\n";}
    }
}