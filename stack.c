#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 5
int stack[size];
int top=-1;
int Isstackfull()
{
  return top==size-1;
}
 int Isstackempty()
{
return top==-1;
}
 void push(int item)
{
 if(Isstackfull())
{
 printf("stack is overflow!cannot push%d\n",item);
}
else
{
 top++;
 stack[top]=item;
 printf("%d pushed to stack \n",item);
}
}
 void pop()
{
 if(Isstackempty())
{
 printf("stack underflow!no elements to pop\n");
}
else
{
 int item=stack[top];
 top--;
 printf("%d popped from stack\n",item);
}
}
void display()
{
int i;
if(top>=0)
{
 printf("\n the elements in stack\n");
 for(i=top;i>=0;i--)
 printf("\n%d",stack[i]);
 printf("\n enter next choice");
}
 printf("\nstack contents are as....");
  for(i=top;i>=0;i--)
 printf("\n%d",stack[i]);
}
void main()
{
int choice,value;
clrscr();
while(1)
{
printf("\n stack operations menu:\n");
printf("1.push\n2.pop\n3.dispaly\n4.exit\n");
printf("enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1:
 printf("enter value to push:");
 scanf("%d",&value);
 push(value);
 break;
case 2:
 pop();
 break;
case 3:
 display(stack);
 break;
case 4:
 exit(0);
 default:
 printf("invalid choice!please try again\n");
 break;
}
}
};