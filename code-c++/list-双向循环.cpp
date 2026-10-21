#include<bits/stdc++.h>
using namespace std;
struct listnode
{
    int data;
    listnode *next,*prev;
    listnode():data(),next(nullptr),prev(nullptr){};
    listnode(int x):data(x),next(nullptr),prev(nullptr){};
};
int main()
{
    int n;cin>>n;
    listnode *head=new listnode();
    listnode *tail=head;
    for(int i=0;i<n;i++)
    {
        int m;cin>>m;
        listnode *p=new listnode(m);
        tail->next=p;
        p->prev=tail;
        tail=p;
    }
    tail->next=head;
    head->prev=tail;
    return 0;
}