#include<bits/stdc++.h>
using namespace std;
struct listnode
{
    int date;listnode *next,*last;
    listnode(int x):date(x),next(nullptr),last(nullptr){}
};
listnode* lianjie(int n,int a[])
{
    vector<listnode*>node(n);
    for(int i=0;i<n;i++)
    {
        node[i]=new listnode(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        node[i]->next=(i+1<n)?node[i+1]:nullptr;
        node[i]->last=(i-1>=0)?node[i-1]:nullptr;
    }
    return node[0];
}
listnode* shanchu(listnode *head,int x)
{
    if(head==nullptr) return nullptr;          

    head->next = shanchu(head->next,x);       
    if(head->date==x)                          
    {
        listnode *a=head->next;
        if(head->next) head->next->last=head->last;
        delete head;
        return a;                        
    }
    return head;                              
}
void fanhui(listnode *head)
{
    int cnt=0,cnt1=0;
    if(head==nullptr)return ;
    for(listnode *p=head;cnt!=2&&p!=nullptr;)
    {
        if(cnt1==0)
        {
        cout<<p->date<<" ";
        if(p->next==nullptr){cnt1=1-cnt1;cnt++;}
        else{p=p->next;}
        }
        else if(cnt1==1)
        {
            cout<<p->date<<" ";
            if(p->last==nullptr){cnt1=1-cnt1;cnt++;}
            else{p=p->last;}
        }
    }
}
int main()
{
    int n,x;cin>>n>>x;
    int a[n];listnode *head;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    head=lianjie(n,&a[0]);
    head=shanchu(head,x);
    fanhui(head);
}