#include <stdio.h>

int sort(int *, int);
void print_int_arr(int *, int);
int sortedSolution(int [], int);


/*
OddOccurrencesInArray
Find the value that doesn't have a match.
*/


int main(){

	int arr[] = { 1, 2, 4, 4, 3, 3, 2, 6, 6, 10, 1 };
	int size = 11;
	int odd;	

	odd = sortedSolution(arr, size);

	printf("Array: ");
	print_int_arr(arr, size);
	printf("Odd number is %d\n", odd);

	return 0;
}



int sortedSolution(int A[], int N){
	
	int i, odd;
	
	sort(A, N); 

	// edge case
	if(A[0] != A[1]){
		odd = A[0];
	}
	else{
		odd = A[N - 1];
		for(int i = 2; i < N - 1; i += 2){
			if(A[i] != A[i + 1]){
				odd = A[i];
			}
		}
	}

	return odd;
}

int sort(int *A, int N){

	int i, x, tmp;
	
	for(i = 0; i < N; i++){
		for(x = i + 1; x < N; x++){
			if(A[i] > A[x]){
				tmp = A[i];
				A[i] = A[x];
				A[x] = tmp;
			}
		}
	}
	
	return 0;
}


void print_int_arr(int *arr, int N){

	int i;
	
	for(i = 0; i < N; i++){
		printf("%d ", arr[i]);
	}
	
	printf("\n\n");
}

