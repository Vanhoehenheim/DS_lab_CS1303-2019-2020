#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[6]= {0,10,20,30,40,50};
    int low=0,high=4,mid;
    int ele,found=0;

    printf("enter number:");
    scanf("%d",&ele);

    while(low<=high)
    {
        mid=(low+high)/2;

        if(ele==a[mid])
        {
            found=1;
            break;
        }

        else if(ele<a[mid])
            high=mid+1;
        else
            low=mid+1;

    }

    if(found==1)
        printf("element is found");
    else
        printf("element not found");

    return 0;

}
