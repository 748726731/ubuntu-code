#include<bits/stdc++.h>
using namespace std;
struct Listnode
{
    string name;
    Listnode* next;
    Listnode(string na):name(na){}
};
Listnode* connect(string na, Listnode* head) {
    Listnode* p = new Listnode(na);
    p->next = head;      // 新节点指向旧的头
    return p;            // 新节点成为新的头
}
Listnode *sort(Listnode* p)
{

}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<string>name;
    for(int i=0;i<n;i++)
    {
        string n;cin>>n;
        name.push_back(n);
    }
    Listnode *head=nullptr;
    for(int i=0;i<n;i++)
    {
        head=connect(name[i],head);
    }

}