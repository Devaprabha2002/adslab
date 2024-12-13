#include <stdio.h>
#include<stdlib.h>
void insertion();
void display();
void deletion();
#define MAX 5
int cqueue[MAX];
int front=-1;
int rear=-1;
int IsQueueFull()
{
    return(rear+1)%MAX==front;
    
}
int IsQueueEmpty()
{
    front==-1;
    
}
void enqueue()
{
    if (IsQueueFull())
    {
        printf("Queue overflow.\n");
        return;
        
    }
  int value;
  printf("enter  value to enqueue:");
  scanf("%d",&value);
  if (IsQueueEmpty())
  {
      front=0;
      
  }
    
rear=(rear+1)%MAX;
cqueue[rear]=value;
printf("Enqueued %d onto queue\n",value);

}
void dequeue()
{
    if(IsQueueEmpty())
    {
        printf("Dequeued %d from queue\n",cqueue[front] );
        if(front==rear)
        {
            front=rear=-1;
            
        }
        else
        {
            front=(front+1)%MAX;
            
        }
    }
}
void checkfirst()
 {
      if(IsQueueEmpty())
      {
          printf("Queue is Underflow\n");
          
      }
      else
      {
          printf("1st element:%d\n",cqueue[front]);
          
      }
 }
void checklast()
 {
      if(IsQueueEmpty())
      {
          printf("Queue is Underflow\n");
          
      }
      else
      {
          printf("Last element:%d\n",cqueue[front]);
          
      }
 } 
 int main()
 {
     int choice;
     while(1)
     {
         printf("\nMenu\n1.Enqueue\n2.Dequeue\n3.First Element\n4.Last Element5.Exit\n");
         printf("\nEnter your choice:");
         scanf("%d,&choice");
         switch(choice)
         {
             case 1:
                  enqueue();
                  break;
            case 2:
                  dequeue();
                  break;
            case 3:
                  checkfirst();
                  break;
            case 4:
                  checklast();
                  break;
            case 5:
                  exit(0);
            default:
                  printf("Invalid choice\n");
                  
         }
         
         
     }
return 0;
 }