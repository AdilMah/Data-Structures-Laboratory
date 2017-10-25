#include<stdio.h>
#include<limits.h>
/////////////////////////////////////////////////////////////////////
const int capacity=100;//Global variable
int parr[capacity]; //Heap implemented as an array
int size=0;         //Keeps counter of the current size of the heap
////////////////////////////////////////////////////////////////////
//Helper Functions
int parent(int i)
  {return (i-1)/2;}

int left(int i)
  {return 2*i+1;}

int right(int i)
  {return 2*i+2;}
  
void swap(int* a,int* b)
{
  *a=*a+*b;
  *b=*a-*b;
  *a=*a-*b;
}
void Maxheapify(int i)//To maintain the max_heap property
{
  int lt=left(i);
  int rt=right(i);
  int largest=i;
  
  if(lt<size && parr[lt]>parr[i])//Swaps the value of a node with max of
        largest=lt;                  //left and Right child
  if(rt<size && parr[rt]>parr[largest])
        largest=rt;
  if(largest!=i)
    {
      swap(&parr[largest],&parr[i]);
      Maxheapify(largest);
    }
}

////////////////////////////////////////////////////////////////////////
int extractmax()//Function that returns and del the maximum or the topmost value
{
  if(size<=0)
    return INT_MIN;
  if(size==1)
    {
	size--;
    return parr[0];
	}
  
  int root=parr[0];
  parr[0]=parr[size-1];
  size--;
  
  Maxheapify(0);
  
  return root;
}
  
void insertkey(int k)
{
    if(size==capacity)
  {
    printf("\nOverflow:No more memory left");
    return;
  }
  size++;
  int i=size;
  parr[i]=k;
  
  while(i!=0 && parr[parent(i)]<parr[i])//Shifting Up 
  {
    swap(&parr[i],&parr[parent(i)]);
    i=parent(i);
  }
}


void DecreaseKey(int i,int value)
{
  parr[i]=value;
  while(i!=0 && parr[parent(i)]<parr[i])
    {swap(&parr[parent(i)],&parr[i]);
    i=parent(i);}
}


int main()
{
 insertkey(56);
 insertkey(21);
 insertkey(10);
 insertkey(98);
 insertkey(-58);
 insertkey(2);
 insertkey(51);
 insertkey(59);
 insertkey(62);
 insertkey(44);
 insertkey(11);
 insertkey(22);
 int result;
 while(1)
 {
   result=extractmax();
   if(result==INT_MIN)break;
          
   printf("%d\n",result);
 }
}
 
