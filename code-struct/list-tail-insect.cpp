#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int Data;
    ListNode* next,*prev;
};
int main()
{
    int n;cin>>n;
    ListNode *head=nullptr;
    ListNode *tail=head;
    for(int i=0;i<n;i++)
    {
        int data;cin>>data;
        ListNode *p=new ListNode();
        p->Data=data;p->next=p->prev=nullptr;
        if(head==nullptr)
        {
            head=tail=p;
        }
        else
        {
            tail->next=p;
            p->prev=tail;
            tail=p;
        }
    }
    int cnt=1;
    while(true)
    {
        ListNode *output=head;
        cout<<head->Data;
        if(cnt==2){head=head->prev;}
        else if(cnt==1){head=head->next;}
        if(cnt==1&&head->next==nullptr){cnt=2;}
        else if(cnt==2&&head==nullptr)break;
        
    }
}