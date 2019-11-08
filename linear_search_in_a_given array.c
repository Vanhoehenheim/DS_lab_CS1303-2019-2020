/*
    @brief : This program search element into static Array by linear Searching Algorithm.
    @issue : what happen is User give the value of size > 50.....
             Here Array a[50] is capable to hold 50 elemets only
    @Solution : We can notify usher that the value of size must be less then 50....         

*/
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
   int ele,found=0, i; //@issue : No need to use a variable "i" here. we have "c" variable already and unused at this time.

    printf("enter the element to search: ");
    scanf("%d",&ele);

    for(i=0;i<5;i++) //@issue : We cann't confined search upto 5 only we have to go as long as elemts are available into array.
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
