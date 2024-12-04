#include<stdio.h>
#include<stdlib.h>
void main()
{
int i,j,k,m,n,a[10],b[10],c[20];
clrscr();
printf("\n enter the size of first array:");
scanf("%d",&m);
printf("\n enter the sorted elements of first array:");
for(i=0;i<m;i++)
{
scanf("%d",&a[i]);
}
printf("\n enter the size of second array:");
scanf("%d",&n);
printf("\n enter the sorted elements of second array:");
for(j=0;j<n;j++)
{
scanf("%d",&b[j]);
}
i=j=k=0;
for(k=0;k<m+n;k++)
{
if(i<m&&j<n)
{
if(a[i]<b[j])
{
c[k]=a[i];
i++;
}
else
{
c[k]=b[j];
j++;
}
}
else if(i<n)
{
c[k]=a[i];i++;
}
else
{
c[k]=b[j];j++;
}
}
printf("\n the merged array is:");
for(k=0;k<m+n;k++)
{
printf("%d",c[k]);
}
getch();
}