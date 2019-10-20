#include <stdio.h>
#include <stdlib.h>

// Factorial function
int fact(int n) {
	if(n < 0){
	    printf("Invalid input");
	    exit(0);
	}
	if(n == 0) {
		return 1;
	}
	
	int smallAns = fact(n - 1);
	return n * smallAns;
}

int main()
{
    int n;
    printf("Enter n: ");                            //Enter your number
    scanf("%d", &n);
    printf("Factorial of %d is %d", n, fact(n));    //Print the factorial of number

    return 0;
}
