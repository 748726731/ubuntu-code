#include<bits/stdc++.h>
using namespace std;
struct QueueNode{
    int data;
    QueueNode *next;
};
struct Queue{
    QueueNode *front,*tail;int cnt;
};
void creat(Queue *&s)
{
    s=new Queue();//划分了一个内存，大小为Queue，放的是Queue
    //s的地址是内存的首部,new返回的是地址
    s->cnt=0;
    QueueNode *dummy=new QueueNode();//设了一个装QUeueNode地址的node,
    //为他划分内存，大小为QueueNode整个的字节数,把首部的地址传给node
    dummy->data=0;dummy->next=nullptr;
    s->front=dummy;s->tail=dummy;
}
void destory(Queue *&s)
{
    for(QueueNode *p=s->front->next,*q;p;p=q)
    {
        q=p->next;
        delete p;
    }
    delete s->front;
    delete s;
    s=nullptr;
}
void entry(Queue *s,int x)
{
    QueueNode *p=new QueueNode();p->data=x;p->next=nullptr;
    s->tail->next=p;s->tail=p;
    s->cnt++;
}
bool pop(Queue *s,int &x)
{
    if(s->cnt==0)return false;
    QueueNode *p=s->front->next;
    x=p->data;
    s->front->next=p->next;
    if(p==s->tail)s->tail=s->front;
    s->cnt--;
    delete p;
    return true;
}
int main()
{
    int x;//用来存数据
    Queue *s;
    creat(s);//节点
    /*
    entry,pop 
    */
   destory(s);
}