#include<stdio.h>
void ascend(int a[],int n)
{
  int i,j,t=a[0];
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
	if(a[i]>a[j])
	 {
	  t=a[i];
	  a[i]=a[j];
	  a[j]=t;
	 }
}
}
printf("\nThe Ascending order is:");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
}
