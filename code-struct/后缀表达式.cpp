#include<bits/stdc++.h>
using namespace std;
char content[]="82/2+56*-";
//----------------------------Stack
struct Stack{
    int *data;
    int top;
};
Stack *settingStack(void)
{
    Stack *s=(Stack *)malloc(sizeof(Stack));
    s->data=(int *)malloc(sizeof(int)*100);
    return s;
}
void pop(Stack *s,int *x){
    *x=s->data[s->top];
    s->top=s->top-1;
}
void push(Stack *s,int *x){
    s->top=s->top+1;
    s->data[s->top]=*x;
}
void destroy(Stack *s){
    free(s->data);
    free(s);
}
//-------------------------------
typedef enum{
    add,minu,multiply,divide,modulo,nul,num
}enumetare;
enumetare getToken(char *symbol,int *index)
{
    *symbol=content[*index];
    (*index)++;
    switch(*symbol)
    {
        case '+':return add;
        case '-':return minu;
        case '*':return multiply;
        case '/':return divide;
        case '%':return modulo;
        case '\0':return nul;
        default :return num;
    }
}
//----------------------------------
int main()
{
    Stack *s=settingStack();
    s->top=-1;

    char symbol;
    int a,b;//拿出来计算的
    int result=917867;
    int index=0;
    while(result==917867)
    {
        enumetare token=getToken(&symbol,&index);
        if(token==num)
        {
            int k=symbol-'0';
            push(s,&k);
        }
        else
        {
            int t;
            switch(token)
            {
            case add:{pop(s,&b);pop(s,&a);t=a+b;push(s,&t);break;}
            case minu:{pop(s,&b);pop(s,&a);t=a-b;push(s,&t);break;}
            case multiply:{pop(s,&b);pop(s,&a);t=a*b;push(s,&t);break;}
            case divide:{pop(s,&b);pop(s,&a);t=a/b;push(s,&t);break;}
            case modulo:{pop(s,&b);pop(s,&a);t=a%b;push(s,&t);break;}
            default :{pop(s,&result);break;}
            }
        }
    }
    cout<<result;
}