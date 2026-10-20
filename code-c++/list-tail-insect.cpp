#include<bits/stdc++.h>
using namespace std;
struct Listnode
{
    string name;
    Listnode* next;
    Listnode(string na):name(na),next(nullptr){}
    Listnode():name(),next{nullptr}{}
};
int main(){
    Listnode *head=new Listnode();
    Listnode* tail=head;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        string name;cin>>name;
        Listnode *p=new Listnode(name);
        tail->next=p;
        tail=p;
    }
    for(Listnode *i=head->next;i!=nullptr;i=i->next)
    {
        cout<<i->name<<endl;
    }
}