#include<stdio.h>
#include<stdlib.h>
struct Node
{
 int data;
 struct Node*next;
 struct Node*prev;
};
struct Node*createNode(int data)
{
struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
newNode->data=data;
newNode->next=NULL;
newNode->prev=NULL;
return newNode;
}
void insertEnd(struct Node**head,int data)
{
 struct Node*newNode=createNode(data);
 struct Node*temp=*head;
 if(*head==NULL)
{
    *head=newNode;
    return;
}
while(temp->next!=NULL)
{
     temp=temp->next;
}
temp->next=newNode;
newNode->prev=temp;
}
void deleteNode(struct Node**head,int data)
{
struct Node*temp=*head;
while(temp!=NULL && temp->data!=data)
{
temp=temp->next;
}
if(temp==NULL)
{
printf("Node with data %d not found.\n",data);
return;
}
if(temp->prev!=NULL)
{
temp->prev->next=temp->next;
}
else
{
*head=temp->next;
}
if(temp->next!=NULL)
{
temp->next->prev=temp->prev;
}
free(temp);
printf("Node with data %d deleted .\n",data);
}
void searchNode(struct Node*head,int data)
{
struct Node*temp=head;
int position=1;
while(temp!=NULL)
{
 if(temp->data==data)
 {
  printf("node with data %dfound at position %d.\n",data,position);
  return;
 }
 temp=temp->next;
 position++;
 }
  printf("Node with data %d not found.\n",data);
 }
void displaylist(struct Node*head)
{
struct Node*temp=head;

 if(head==NULL)
{
printf("list is empty.\n");
return;
}

printf("doubly linkedlist:");
while(temp!=NULL)
{
printf("%d",temp->data);
temp=temp->next;
}
printf("\n");
}
int main()
{
 struct Node*head=NULL;
 int choice,value;
while(1)
{
printf("\n doubly linked list menu:\n");
printf("1.insert at end\n");
printf("2.delete node\n");
printf("3.search node\n");
printf("4.display list\n");
printf("5.exit\n");
printf("enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
 printf("enter value to insert:");
 scanf("%d",&value);
 insertEnd(&head,value);
 break;
case 2:
 printf("enter value to delete:");
 scanf("%d",&value);
 deleteNode(&head,value);
 break;
case 3:
  printf("Enter value to search:");
  scanf("%d",&value);
  searchNode(head,value);
  break;
case 4:
 displaylist(head);
 break;
case 5:
exit(0);
default:
printf("invalid choice.please try again.\n");
}
}
}



