#include <stdio.h>
#include<stdlib.h>
void insertion();
void display();
void deletion();
#define MAX 10
int queueArray[MAX];
int rear=-1;
int front=-1;
void main()
{
    int choice;
    while(1)
    {
        printf("\nQueue Operations\n1.Enqueue\n2.Dequeue\n3.Display elements\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
             insertion();
             break;
            case 2:
             deletion();
             break;
            case 3:
              display();
              break;
            case 4:
              exit(1);
            default:
              printf("Wrong choice. Try again!");
        }
    }
}
void insertion()
{
     int addItem;
     if (rear==MAX-1)
       printf("Queue is Overflow\n");
     else 
       {
          if (front==-1)
           front=0;
           printf("Enter the elemnt to be inserted:");
           scanf("%d",&addItem);
           rear=rear+1;
           queueArray[rear]=addItem;
           printf("%d is inserted to queue",addItem);
      }
}
void deletion()
{
    if(front==-1||front>rear)
    {
        printf("Queue is Underflow\n");
        return;
    
    }
    else
    {
        printf("%d is deleted from queue\n",queueArray[front]);
        front=front+1;
        
    }
}
void display()
{
    int i;
     if(front==-1||front>rear)
      {
        printf("Queue is Empty");
      }   
          
    else
      {
      printf("Elements in queue are:");
      for(i=front;i<=rear;i++)
        printf("\t%d",queueArray[i]);
       
      }
        
        
}