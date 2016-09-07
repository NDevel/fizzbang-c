#include <stdio.h>

void print_int_arr(int *, int);



/* Moves each array element to the left 
	The last element is pushed to the from of the array
*/

int main(){

	int i, x, tmp, tmp2;
		
	int A[] = {3, 8, 9, 7, 6 };
	int N = 5;

	print_int_arr(A, N);
		
	for(x = 0; x < K; x++){
		tmp = A[N-1];
		for(i = 0; i < N; i++){
			tmp2 = A[i]; 
			A[i] = tmp; 
			tmp = tmp2; 
		}
	} 
	
	print_int_arr(A, N);	
	
	return 0;
}


void print_int_arr(int *arr, int N){

	int i;
	
	for(i = 0; i < N; i++){
		printf("%d ", arr[i]);
	}
	
	printf("\n\n");
}
