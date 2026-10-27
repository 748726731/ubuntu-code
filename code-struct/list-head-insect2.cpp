#include<bits/stdc++.h>
using namespace std;
struct Listnode
{
    string name;
    Listnode* next;
    Listnode(string name):name(name),next(nullptr){}
};
int main()
{
    Listnode *head=nullptr;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        string name;cin>>name;
        Listnode *p=new Listnode(name);
        p->next=head;
        head=p;
    }
    for(Listnode *i=head;i!=nullptr;i=i->next)
    {
        cout<<i->name<<endl;
    }
}