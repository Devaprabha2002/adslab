#include<stdio.h>
struct Disjointset
{
 int parent[10];
 int rank[10];
 int n;
}dis;
void makeSet()
{
 int i;
 for(i=0;i<dis.n;i++)
 {
 dis.parent[i]=i;
 dis.rank[i]=0;
 }
}
void displaySet()
{
int i;
printf("\n Parent Array\n");
for(i=0;i<dis.n;i++)
{
printf("%d\t",dis.parent[i]);
}
printf("\nRank Array\n");
for(i=0;i<dis.n;i++)
{
  printf("%d\t",dis.rank[i]);
}
printf("\n");
}
int find(int x)
{
if(dis.parent[x]!=x)
{
dis.parent[x]=find(dis.parent[x]);
}
 return dis.parent[x];
}
void unions(int x,int y)
{
int xset=find(x);
int yset=find(y);
if(xset==yset)
   return;
if(dis.rank[xset]<dis.rank[yset])
{
dis.parent[xset]=yset;
dis.rank[xset]=-1;
}
else if(dis.rank[xset]>dis.rank[yset])
{
dis.parent[yset]=xset;
dis.rank[yset]=-1;
}
else
{
dis.parent[yset]=xset;
dis.rank[xset]=dis.rank[xset]+1;
dis.rank[yset]=-1;
}
}
void main()
{
int x,y,ch;
clrscr();
while(1)
{
printf("\n____Menu___\n");
printf("1.Makeset\n2.union\n3.find\n4.display\n5.exit\n");
printf("enter choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("enter no: of elements in a set:");
scanf("%d",&dis.n);
makeSet();
break;
case 2:
 printf("Enter elements to perform union");
 scanf("%d %d",&x,&y);
 unions(x,y);
 break;
case 3:
 printf("Enter elements to check if connected components");
 scanf("%d %d",&x,&y);
 if(find(x)==find(y))
 printf("connected components\n");
 else
 printf("Not connected components\n");
 break;
case 4:
 displaySet();
 break;
case 5:exit(0);break;
 }
 }
 }
