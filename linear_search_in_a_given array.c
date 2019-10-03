#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[5]={23,4,423,56,76};
    int ele,found=0, i;

    printf("enter the element to search: ");
    scanf("%d",&ele);

    for(i=0;i<5;i++)
       {
         if (a[i]==ele)
           {
            found=1;
             printf("found at index %d \n",i);
             break;
           }
       }
        if (found==1)
            printf("element is found");
        else
            printf("element is not found");
    return 0;



}
