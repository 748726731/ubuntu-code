#include<bits/stdc++.h>
using namespace std;
struct Listnode
{
    string name;
    Listnode *next;
    Listnode():name(),next(nullptr){}
    Listnode(string name):name(name),next(nullptr){}
};
int main()
{
    Listnode *head=new Listnode();
    Listnode *tail=head;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        string name;cin>>name;
        Listnode *p=new Listnode(name);
        p->next=head->next;
        head->next=p;
        tail=p;
    }
    for(Listnode *i=head->next;i!=nullptr;i=i->next)
    {
        cout<<i->name<<endl;
    }
}