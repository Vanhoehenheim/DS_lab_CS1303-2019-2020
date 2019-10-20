#include <stdio.h>
#include <stdlib.h>

// Fibonacci function
int fib(int n) {
    
    if(n < 0){
	    printf("Invalid input");
	    exit(0);
	}
		
	if(n == 0 || n == 1) {
		return n;
	}
	
	return fib(n - 1) + fib(n - 2);
	
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("The %dth fibonacci number is %d", n, fib(n));   //Prints the nth fibonacci number

    return 0;
}
