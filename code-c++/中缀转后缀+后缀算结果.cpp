#include<bits/stdc++.h>
using namespace std;
//------------------全局----------------
#define MAXSIZE 100
enum contentType{
    leftt,rightt,add,minuss,multiply,divide,modulo,nul,num
};//enum自动转只能enum转int，反过来不行。因为int太多了，enum特殊一点
string content;
//-------------------手搓Deque--------------------
struct Deque{
    int *data;
    int head;
    int size;
    Deque(){}
};
Deque *settingDeque(void)
{
    Deque *s=new Deque;
    s->data=new int[MAXSIZE];
    s->head=0;
    s->size=0;
    return s;
}
void push_front(Deque *s,int *x)
{
    for(int i=s->head+s->size-1;i>=s->head;i--)
    {s->data[i+1]=s->data[i];}
    s->data[s->head]=*x;
    s->size++;
}
void push_back(Deque *s,int x)
{
    s->data[s->head+s->size]=x;
    s->size++;
}
int pop_front(Deque *s)
{
    int x=s->data[s->head];
    for(int i=s->head;i<s->head+s->size-1;i++)
    {s->data[i]=s->data[i+1];}
    s->size--;
    return x;
}
int pop_back(Deque *s)
{
    int x=s->data[s->head+s->size-1];
    s->size--;
    return x;
}
void destory(Deque *s)
{
    delete[] s->data;
    delete(s);
}
//-----------------------中缀转后缀-----------------------------
contentType text1(char ch)
{
    switch(ch)
    {
        case '(':return leftt;
        case ')':return rightt;
        case '+':return add;
        case '-':return minuss;
        case '*':return multiply;
        case '/':return divide;
        case '%':return modulo;
        case '\0':return nul;
        default :return num;
    }
}//ch->token

char text2(contentType token)
{
    switch(token)
    {
        case leftt:return '(';
        case rightt:return ')';
        case add:return '+';
        case minuss:return '-';
        case multiply:return '*';
        case divide:return '/';
        case modulo:return '%';
        case nul:return '\0';
        default :return '?';//如果ch是数字的话返回?(其他的容易误判)
    }
}//token->ch

void mula1Tomula2(Deque *a,Deque *b)
{
    int in_text[8]={1,4,2,2,3,3,3,0};
    int out_text[8]={4,4,2,2,3,3,3,0};

    int index=0;//下标
    contentType token;//leftt,add....
    char ch;//(,+....

    while(true)
    {
        ch=content[index];
        token=text1(ch);

        if(token==nul)break;

        if(token==num){push_back(b,ch-'0');}//!!!!!!数字是ASCII
        else if(token==leftt){push_back(a,token);}//进token，因为要映射优先级表
        else if(token==rightt)
        {
            while(a->data[a->head+a->size-1]!=leftt)//符号栈顶找配对括号
            {
                push_back(b,text2((contentType)pop_back(a)));//删符号栈栈顶，拿到栈顶,栈顶转符号
            }
            pop_back(a);//删掉配对括号，原右括号不鸟
        }
        else//接下来就是加减乘除
        {
            while(a->size>0&&in_text[a->data[a->head+a->size-1]]>=out_text[token])
            //比一比 原来等待进入的符号优先级 是否比 现在准备进入的符号优先级 大
            //如果大，那就把栈a的拿出来，丢b里，如果小，就把大的压a里，反正最后还要从尾到头一次性压到b里;
            {
                push_back(b,text2((contentType)pop_back(a)));
            }
            push_back(a,(int)token);//压进a的是contentType类型，但是可以转成int类型,因为push_back函数
            //然后a是一个int栈,所以text2((contentType)pop_back(a)))
            //pop a拿出来是一个int，给他转成contentType
        }
        index++;
    }
    while(a->size>0)
    {
        push_back(b,text2((contentType)pop_back(a)));
    }
}
//---------------------计算后缀----------------------------
int evaluate(Deque *b)
{
    Deque *p=settingDeque();//临时栈
    int x,y;
    while(true)
    {
        if(b->size==0)break;
        int c=pop_front(b);
        if(c>=0&&c<=9)
        {
            push_back(p,c);
        }
        else{
            switch(c){
                case '+':
                {
                    y=pop_back(p);
                    x=pop_back(p);
                    int t=x+y;
                    push_back(p,t);
                    break;
                }
                case '-':
                {
                    y=pop_back(p);
                    x=pop_back(p);
                    int t=x-y;
                    push_back(p,t);
                    break;
                }
                case '*':
                {
                    y=pop_back(p);
                    x=pop_back(p);
                    int t=x*y;
                    push_back(p,t);
                    break;
                }
                case '/':
                {
                    y=pop_back(p);
                    x=pop_back(p);
                    int t=x/y;
                    push_back(p,t);
                    break;
                }
                case '%':
                {
                    y=pop_back(p);
                    x=pop_back(p);
                    int t=x%y;
                    push_back(p,t);
                    break;
                }
            }
        }
    }
    x=pop_back(p);
    destory(p);
    return x;
}
//-----------------------main-----------------------------
int main()
{
    cin>>content;
    Deque *a=settingDeque();//符号栈
    Deque *b=settingDeque();//后缀栈

    cout<<"中缀:"<<content<<endl;
    mula1Tomula2(a,b);
    cout<<"后缀:";
    for(int i=0;i<b->size;i++)
    {
        if(b->data[i]>=0&&b->data[i]<=9)cout<<b->data[i];
        else cout<<(char)b->data[i];
    }
    cout<<endl;
    cout<<"结果:"<<evaluate(b)<<endl;

    destory(a);
    destory(b);
}