#include<stdio.h>
#include "sort.h"
int main()
{
  int n,i;
 printf("\nEnter no. of integers:");
 scanf("%d",&n);
int arr[n];
printf("\nEnter the integers:");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
ascend(arr, n);
descend(arr, n);
printf("\n");

}

