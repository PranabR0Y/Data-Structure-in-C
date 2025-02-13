#include<stdio.h>
#define MX 100
struct Stack
{
    int top;
    int data[MX];
};
void push(struct Stack *s,int item)
{
    if((*s).top<MX)//(*s).top is alternate of s->top
    {
        s->data[s->top]=item;
        s->top+=1;
    }
    else

    {
        printf("Stack is Full\n");
    }
}
int pop(struct Stack *s)
{
    int item;
    if(s->top==0)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else

    {
        (*s).top-=1;
        item=(*s).data[s->top];

    }
    return item;
}
int main()
{
    struct Stack stk;
    stk.top=0;
    for(int i=0;i<10;i++)
    {
        push(&stk,i+1);
    }
    for(int i=0;i<10;i++)
        printf("%d\n",pop(&stk));
    printf("%d",pop(&stk));
    return 0;
}
