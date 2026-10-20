#include<bits/stdc++.h>
using namespace std;
struct Listnode
{
    int date;
    Listnode *next;
    Listnode():date(),next(nullptr){}
    Listnode(int date):date(date),next(nullptr){}
};
int find(Listnode *head,int number)
{
    int cnt=0;
    for(Listnode *p=head->next;p!=nullptr;p=p->next)
    {
        cnt++;
        if(p->date==number)return cnt;
    }
    return 20000000;
}
void insect(Listnode *head,int number,int cnt)
{
     int cntt=0;
    for(Listnode *i=head->next;i!=nullptr;i=i->next)
    {
        cntt++;
    }
    if(cnt>cntt){cout<<"链表没有那么多位"<<endl;return;}
    Listnode *p=head;
    for(int i=0;i<cnt;i++)
    {
        p=p->next;
    }
    Listnode *s=new Listnode(number);
    s->next=p->next;
    p->next=s;
    for(Listnode *i=head->next;i!=nullptr;i=i->next)
    {
        cout<<i->date<<" ";
    }
}
void delet(Listnode *head,int number)
{
    for(Listnode *i=head;i->next!=nullptr;)//i是前驱，i=head
    //i管理i->next
    {
        if(i->next->date==number)
        {
            Listnode *p=i->next;
            i->next=i->next->next;
            delete p;
        }
        else i=i->next;//若前面的删掉了，且前面的是尾巴，就不能前进了。
        //在for里是无条件前进的。
}
    for(Listnode *i=head->next;i!=nullptr;i=i->next)
    {
        cout<<i->date<<" ";
    }
}
void change(Listnode *head,int change_number,int number)
{
    for(Listnode *p=head->next;p!=nullptr;p=p->next)
    {
        if(p->date==change_number)p->date=number;
    }
    for(Listnode *i=head->next;i!=nullptr;i=i->next)
    {
        cout<<i->date<<" ";
    }
}
int main()
{
    int n;
    Listnode *head=new Listnode();
    Listnode *tail=head;
    cout<<"what the number of the list:"<<endl;
    cin>>n;cout<<"Please input"<<endl;
    for(int i=0;i<n;i++)
    {
        int date;
        cin>>date;
        Listnode *p=new Listnode(date);
        tail->next=p;
        tail=p;
    }
    string operate;
    cout<<endl<<"你的操作是:";
    cin>>operate;
    if(operate=="find")
    {
        int number;
        cout<<"你要查找哪个数:";cin>>number;
        int cnt;
        cnt=find(head,number);
        if(cnt!=20000000)printf("他在第%d位",cnt);
        else cout<<"NULL";
    }
    else if(operate=="insect")
    {
        int cnt,number;
        cout<<"请依次输入要插入什么数字，在第几位的后面:";
        cin>>number>>cnt;
        insect(head,number,cnt);
    }
    else if(operate=="delete")
    {
        int number;
        cout<<"请输入要删除什么数:";
        cin>>number;
        delet(head,number);
    }
    else if(operate=="change")
    {
        int number,change_number;
        cout<<"依次输入遇到什么数改成什么数:";
        cin>>change_number>>number;
        change(head,change_number,number);
    }
}