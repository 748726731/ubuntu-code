#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 100

typedef enum{
    leftt, rightt, add, minu, multiply, divide, modulo, nul, num
}contentType;

char content[] = "x/(i-j)*y";
//------------------------------------------------------
struct Stack{
    int *data;
    int top;
};
Stack *settingStack(void)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * MAXSIZE);
    s->top = 0;
    s->data[0] = nul;
    return s;
}
void push(Stack *s, int x)
{
    s->top = s->top + 1;
    s->data[s->top] = x;
}
void pop(Stack *s, int *x)
{
    *x = s->data[s->top];
    s->top = s->top - 1;
}
void destroy(Stack *s)
{
    free(s->data);
    free(s);
}
//-----------------------------------------------------------
contentType getToken(char *symbol, int *index)
{
    *symbol = content[*index];
    (*index)++;

    switch(*symbol)
    {
        case '(':  return leftt;
        case ')':  return rightt;
        case '+':  return add;
        case '-':  return minu;
        case '*':  return multiply;
        case '/':  return divide;
        case '%':  return modulo;
        case '\0': return nul;
        default:   return num;
    }
}
void printToken(contentType t)
{
    switch(t)
    {
        case add:      printf("+");  break;
        case minu:     printf("-");  break;
        case multiply: printf("*");  break;
        case divide:   printf("/");  break;
        case modulo:   printf("%%"); break;
        default: break;
    }
}
void postfix(Stack *s)
{
    int in_stack[8]  = { 0, 19, 12, 12, 13, 13, 13, 0 };
    int out_stack[8] = {20, 19, 12, 12, 13, 13, 13, 0 };

    contentType token;//从原字符串中提取的一个个字符，通过gettoken转化;
    int  index = 0;//下标
    char symbol;
    int  x;

    token = getToken(&symbol, &index);

    while(token != nul)
    {
        if(token == num)
        {
            printf("%c", symbol);
        }
        else if(token == leftt)
        {
            push(s, token);
        }
        else if(token == rightt)
        {
            while(s->data[s->top] != leftt)
            {
                pop(s, &x);
                printToken((contentType)x);
            }
            pop(s, &x);
        }
        else
        {
            while(s->top > 0 &&in_stack[s->data[s->top]] >= out_stack[token])//当栈顶的优先级大于此运算符号的优先级时
            {
                pop(s, &x);
                printToken((contentType)x);
            }
            push(s, token);
        }

        token = getToken(&symbol, &index);
    }

    while(s->top > 0)
    {
        pop(s, &x);
        printToken((contentType)x);
    }

    printf("\n");
}
//--------------------------------------------
int main()
{
    Stack *s = settingStack();

    printf("中缀: %s\n", content);
    printf("后缀: ");
    postfix(s);

    destroy(s);
    return 0;
}