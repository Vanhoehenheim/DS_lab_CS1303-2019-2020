#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[50],size, c;
    // take the input of elements and the size of the array
    printf("enter size of array: ");
    scanf("%d",&size);
    printf("enter elements of the array: ");
    
    for (c=0;c<size;c++)
    {
        printf("enter element [%d] : ",c);
        scanf("%d",&a[c]);
    }
    
    // Searching an element 
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
