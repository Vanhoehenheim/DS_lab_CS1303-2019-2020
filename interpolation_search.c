#include<stdio.h>

int interpolationSearch(int data, int arr[], int n) {
	int lo = 0, hi = n-1, mid = -1, index = -1;

	while(lo <= hi) {
		mid = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (data - arr[lo]));

		if (arr[mid] == data) {
			index = mid;
			break;
		} else {
			if(arr[mid] < data) {
				lo = mid+1; // data is larger so data in upper half 
			} else {
				hi = mid-1; // data is smaller so data in lower half 
			}
		}
	}
	return index;
}



int main(int argc, char const *argv[])
{
	int n;
	printf("Please enter the number of elements."); 
    scanf("%d",&n);
    int arr[n];
    printf("\nPlease enter elements to be sorted.\n");
    for(long i=0; i<n ;i++)
      scanf("%d",&arr[i]);

  	int data;
  	printf("Enter data to find : \n");
  	scanf("%d", &data);
  	int index = interpolationSearch(data,arr,n);
  	if(index == -1) {
  		printf("Data not Found\n");
  	} else {
  		printf("Data found at %d index\n", index);
  	}
	return 0;
}