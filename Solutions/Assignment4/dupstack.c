//Creating a dupliacte stack using a temporary stack
//Stack implemented using array
#include<stdio.h>
#define SIZE 100
void push(int st[],int* top,int value)
{
    if(*top==SIZE-1)
        return;
    else
    {
        (*top)++;
        st[*top]=value;

    }
}

int pop(int st[],int* top)
{
    int value=st[*top];
    (*top)--;
    return value;
}

void printstack(int st[],int top)
{   int i;
    if(top==-1)
        printf("Error!!!!\n");
    else
    {
        for(i=top;i>-1;i--)
        {printf("\t\t| %d |\n",st[top]);
         top--;}
    }
}
int main()
{
    int stack[SIZE];
    int temp[SIZE];
    int news[SIZE];
    int top1=-1;
    int top2=-1;
    int top3=-1;
    int i;
    int n,num;
    printf("Enter the number of elements you want to push,max size(%d)",SIZE);
    scanf("%d\n",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d\n",&num);
        push(stack,&top1,num);

    }

    for( i=0;i<n;i++)
    {
        push(temp,&top2,pop(stack,&top1));
    }
    int element;
    for(i=0;i<n;i++)
    {
        element=pop(temp,&top2);
        push(stack,&top1,element);
        push(news,&top3,element);
    }

    printf("::::::::::::Original Stack is::::::::::::\n");
    printstack(stack,top1);
    printf("::::::::::::::Duplicate Stack::::::::::::::::::::\n");
    printstack(news,top3);

}
