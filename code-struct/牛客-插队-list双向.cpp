#include<bits/stdc++.h>
using namespace std;
struct listnode
{
    string name;
    listnode *next,*prev;
    listnode(string name):name(name),next(nullptr),prev(nullptr){}
};
int main()
{
    int number,time;
    cin>>number>>time;
    listnode *dummyH=new listnode("");
    listnode *dummyT=new listnode("");
    dummyH->next=dummyT;
    dummyT->prev=dummyH;
    listnode *tail=dummyH;
    map<string,listnode*>mp;
    for(int i=0;i<number;i++)
    {
        string name;cin>>name;
        listnode *p=new listnode(name);
        mp[name]=p;
        tail->next=p;
        p->prev=tail;
        p->next=dummyT;
        dummyT->prev=p;
        tail=p;
    }//建表

  for(int i=0;i<time;i++)
    {
        string a0,b0;
        cin>>a0>>b0;
        listnode *a=mp.find(a0)->second;
        listnode *b=mp.find(b0)->second;
        if(a==b)continue;
        a->prev->next=a->next;
        a->next->prev=a->prev;
        b->prev->next=a;
        a->prev=b->prev;
        b->prev=a;
        a->next=b;
    }

    for(int i=0;i<number;i++)
    {
        cout<<dummyH->next->name;
        dummyH=dummyH->next;
    }
}