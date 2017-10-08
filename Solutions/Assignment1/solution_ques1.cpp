//Assignment 5-StackPermutation(q1)

#include<stdio.h>
#define SIZE 10

void enqueue(int[],int*,int*,int);
void dequeue(int[],int*,int*);
int isempty(int,int);
void push(int,int[] ,int*);
void pop(int st[],int* );
int view(int q[],int front);

int n;


int main()
{   int stack[SIZE];
    int top=-1;
    int enq[SIZE];
    int deq[SIZE];
    int front1=-1;
    int front2=-1;
    int rear1=-1;
    int rear2=-1;
    int value;
    int i;
    printf("Enter the number of elements::\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
        enqueue(enq,&front1,&rear1,i+1);


     printf("Enter the number with spaces between digits\n");
     for( i=0;i<n;i++)
        {   scanf("%d",&value);
            enqueue(deq,&front2,&rear2,value);
        }


     while(!isempty(front1,rear1))
        {
           int checker=view(enq,front1);
           while(checker!=view(deq,front2))
           {
            push(view(enq,front1),stack,&top);
            dequeue(enq,&front1,&rear1);
            checker=view(enq,front1);
            }

        dequeue(enq,&front1,&rear1);
        dequeue(deq,&front2,&rear2);

        while(stack[top]==deq[front2])
        {
            pop(stack,&top);
            dequeue(deq,&front2,&rear2);
        }

        }


    if(isempty(front2,rear2)&&(top==-1))
          printf("\nCongrats!!!!Its a Stack Permutation(^_^)\n");
    else
        printf("\nSorry!!!!!!!Not a stack Permutation\n");




}

void enqueue(int e[],int *front,int *rear,int num )
{
    if (*rear == n - 1)
    printf("Queue Overflow \n");

    else
    {
        if (*front == - 1)
        *front = 0;
        *rear = *rear + 1;
        e[*rear] = num;
    }


}

void dequeue(int e[],int *front,int *rear)
{
    if (*front == - 1 || *front > *rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        *front = *front + 1;
    }
}


void push(int value,int st[],int *top)
{
    if(*top==n-1)
        printf("Stack Overflow\n");

    else
    {
        (*top)++;
        st[*top]=value;
    }
}

void pop(int st[],int* top)
{
    if(*top==-1)
        printf("Stack Underflow\n");
    else
        (*top)--;

}


int view(int q[],int front)
{
   return q[front];
}


int isempty(int front,int rear)
{
    if(front==-1 || rear<front)
        return 1;
    else
        return 0;
}
