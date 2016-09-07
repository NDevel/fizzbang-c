#include <stdio.h> // printf
#include <math.h> // ceil

int first_try(int, int, int);
int second_try(int, int, int);

/* Count the minimal number of jumps that the small frog must perform to reach its target. 
	Position 1 = X
	Position 2 = Y
	Length of Jump = D

	 X = 10
	 Y = 85
	 D = 30
	 Answer = 3

*/

int main(int argc, int *argv[]){
	
	int x, y, d;
	x = 10; y = 85; d = 30;
	
	printf("First: %d\n", first_try(x, y, d));	
	printf("Second: %d\n", second_try(x, y, d));
	
}

// time : 2 min
int first_try(int X, int Y, int D){

	int e = 0;

	while(X < Y){
		X += D;
		e++;
	}
	
	return e;		
	
}


// performance : 20.
// Issues with gcc compiler flags for math header
int second_try(int X, int Y, int D){

	double jumps = (Y - X) / (D * 1.0);
	jumps = ceil(jumps);
	
	return (int)jumps;
}
