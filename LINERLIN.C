#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node
{
   int data;
   struct Node* next;
};

struct Node*createNode(int data)
{
   struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
   newNode->data=data;
   newNode->next=NULL;
   return newNode;
}

void insertAtBegining(struct Node** head,int data)
{
   struct Node* newNode=createNode(data);
   newNode->next=*head;
   *head=newNode;
   printf("Element %d inserted at the begining\n",data);
}

void insertAtEnd(struct Node** head,int data)
{
   struct Node* temp=*head;
   struct Node* newNode=createNode(data);
   if(*head==NULL)
   {
      *head=newNode;
      printf("Elements %d is inserted at the end\n",data);
      return;
   }
   while(temp->next!=NULL)
   {
      temp=temp->next;
   }
   temp->next=newNode;
   printf("Elements %d is inserted at the end \n",data);
}

void insertAtAny(struct Node** head,int data,int pos)
{
   int i;
   struct Node* temp=*head;
   struct Node* newNode=createNode(data);
   if(pos==1)
   {
      newNode->next=*head;
      *head= newNode;
      printf("Elements %d is inserted at the position%d \n",data,pos);
      return;
   }
   for(i=1;i<pos-1&&temp!=NULL ;i++)
   {
      temp=temp->next;
   }
   if(temp==NULL)
   {
      printf("Position \n");
      free(newNode);
      return;
   }
   newNode->next=temp->next;
   temp->next=newNode;
   printf("Elements %d inserted at position %d\n",data,pos);
}

void deleteAtBegining(struct Node** head)
{
   struct Node* temp;
   if(*head==NULL)
   {
      printf("List is empty");
      return;
   }
   temp=*head;
   printf("Elements %d deleted from the begining\n",temp->data);
   *head=(*head)->next;
   free(temp);
}

void deleteFromEnd(struct Node** head)
{
   struct Node* temp=*head;
   struct Node* prev=NULL;
   if(*head==NULL)
   {
      printf("List is empty\n");
      return;
   }
   if(temp->next==NULL)
   {
      printf("Elements %d deleted from the end\n",temp->data);
      free(temp);
      *head=NULL;
      return;
   }
   while(temp->next!=NULL)
   {
      prev=temp;
      temp=temp->next;
   }
   printf("Elements %d deleted from the end\n",temp->data);
   prev->next=NULL;
   free(temp);
}
void deletefromPosition(struct Node** head,int pos)
{
  int i;
  struct Node* temp=*head;
  struct Node* prev=NULL;
  if(*head==NULL)
  {
     printf("List is empty \n");
     return;
  }
  if(pos==1)
  {
     printf("Element %d deleted from position %d \n",temp->data,pos);
     *head=temp->next;
     free(temp);
     return;
  }
  for(i=1;i<pos&&temp!=NULL ;i++)
  {
     prev=temp;
     temp=temp->next;
  }
  if(temp==NULL)
  {
     printf("Position out of bounds");
     return;
  }
  printf("Elements %d deleted from the position %d\n ",temp->data,pos);
  prev->next=temp->next;
  free(temp);
}

void traverselist(struct Node* head)
{
  struct Node* temp=head;
  if(head==NULL)
  {
     printf("List is Empty \n");
     return;
  }
  while(temp!=NULL)
  {
    printf("%d->",temp->data);
    temp=temp->next;
  }
  printf("NULL\n");
}

int main()
{
  struct Node* head=NULL;
  int choice,data,pos;
  clrscr();
  while(1)
  {
     printf("\n 1.Insert at begining \n");
     printf("\n 2.Insert at end \n");
     printf("\n 3.Insert at position \n");
     printf("\n 4.Delete at begining \n");
     printf("\n 5.Delete at end \n");
     printf("\n 6.Delete at position \n");
     printf("\n 7.Traverse list \n");
     printf("\n 8.Exit\n");
     printf("\n Enter the choice: ");
     scanf("%d",&choice);

     switch(choice)
     {
	case 1: printf("Enter the data to insert at begining:");
		scanf("%d",& data);
		insertAtBegining(&head,data);
		break;

	case 2: printf("Enter the data to insert at the end:" );
		scanf("%d",&data);
		insertAtEnd(&head,data);
		break;

	case 3: printf("Enter data to insert:");
		scanf("%d",&data);
		printf("Enter position");
		scanf("%d",&pos);
		insertAtAny(&head,data,pos);
		break;

	case 4: deleteAtBegining(&head);
		break;

	case 5: deleteFromEnd(&head);
		break;

	case 6: printf("Enter position to delete:");
		scanf("%d",&pos);
		deletefromPosition(&head,pos);
		break;

	case 7: traverselist(head);
		break;

	case 8: exit(0);

	default: printf("/n Invalid Choice");
     }
 }
//     return 0;
}


