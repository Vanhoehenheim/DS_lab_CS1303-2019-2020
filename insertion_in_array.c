#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[50], size, i, num, pos;
    printf("enter size of array: ");
    scanf("%d",&size);
    printf("enter elements of the array: ");

    for(i=0;i<size;i++)
    {
        printf("enter element [%d] : ",i);
        scanf("%d",&a[i]);
    }

    printf("enter value you want to insert: ");
    scanf("%d",&num);
    printf("enter pos: ");
    scanf("%d",&pos);

    // SWAPING ELEMENTS
    for(i=size-1;i>=pos-1;i--)
    {
        a[i+1]=a[i];
    }

    a[pos-1]=num;
    size++;

    if(pos<=0 || pos>size+1)
    {
        printf("position out of bound !");
    }
    else
    {
         for(i=size-1;i>pos-1;i--)
       {
          a[i+1]=a[i];
       }

    a[pos-1]=num;
    size++;
    }
    for(i=0;i<size;i++)
    {
        printf("%d",a[i]);
    }


    return 0;
}
