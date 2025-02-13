#include<stdio.h>
int size=10;
struct queue
{
      
      int data[size+1];
      int front,rear;

};
void enqueue(struct queue* ptr,int item)
{
      if((ptr->rear+1)%(size+1)==ptr->front)
      {
            printf("Full\n");
            return;
      }
      ptr->data[ptr->rear]=item;
      ptr->rear=(ptr->rear+1)%(size+1);

}
int dequeue(struct queue *ptr)
{
      int item;
      if(ptr->rear==ptr->front)
      {
          printf("Empty\n");
            return -1;
      }
      item=ptr->data[ptr->front];
      ptr->front=(ptr->front+1)%(size+1);
      return item;
}
int main()
{
      struct queue ptr;
      ptr.front=ptr.rear=0;
      return 0;
}