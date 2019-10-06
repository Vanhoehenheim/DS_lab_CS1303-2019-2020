#include <stdio.h>

// Calculate numbers above the main diagonal

// Setting the size of the matrix
#define mat 12

int main(){

	// defining the variables

	int line = 0, column = 0;
	double sum = 0, media = 0, M[mat][mat];
	char letter;

	printf("Type S to calculate sum or M to average\n");
	scanf("%c", &letter);

	for(line = 0; line < mat; line++){
		for(column = 0; column < mat; column++){
			scanf("%lf", &M[line][column]);
		}
	}

	if(letter == 'S'){
		for(line = 0; line < mat; line++){
			for(column = 0; column < mat; column++){
				if(line < column){
					sum += M[line][column]; //calculate the sum
				} 
			}
		}
		printf("Sum = %.1f\n", sum);
	}else if(letter == 'M'){
		for(line = 0; line < mat; line++){
			for(column = 0; column < mat; column++){
				if(line < column){
					sum += M[line][column];
					media = (sum / (((mat * mat)-mat)/2)); //calculate the media
				}
			}
		}
		printf("Media = %.1f\n", media);
	}

	return 0;
}
