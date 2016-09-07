#include <stdio.h>

int solution(int [], int);
void quicksort(int *, int, int);
int partition(int *, int, int);
void print_int_arr(int *, int);

/*
	given a zero-indexed array A, returns the value of the missing element.
*/
	

int main(){

	int y[12] = {10, 1, 11, 9, 4, 5, 6, 7, 8, 2, 13, 3 };
	int x = 12;
	
	print_int_arr(y, x);
	printf("Missing element: %d\n", solution(y, x));
	print_int_arr(y, x);
	
	
	return 0;
}

int solution(int A[], int N){
	
	/*
	   known cases 
	   -------------
	   2, 3, 4, 5, 6
	   1, 2, 4, 5, 6
	   1, 2, 4, 5, 7
	   3, 5, 1, 4, 6
	*/
	
	quicksort(A, 0, N-1);

	int i, missing;
	
	if(A[0] == 1){
		missing = A[N-1] + 1;
	}
	else{
		missing = 1;
	}
	
	for(i = 1; i < N; i++){
		if(A[i] != A[i-1] + 1){
			missing = A[i] - 1;
		}
	}

	return missing;
}


int partition(int *A, int st, int end){
	
	int pivot = A[end];
	int i, tmp, pindex;
	
	i = pindex = st;


	for(i; i < end; i++){
		if(A[i] <= pivot){
			tmp = A[i];
			A[i] = A[pindex];
			A[pindex] = tmp;
			pindex++;
		}
	}
	
	tmp = A[pindex];
	A[pindex] = A[end];
	A[end] = tmp;
	
	return pindex;
}

void quicksort(int *A, int st, int end){

	if(st >= end) return;
	int pindex = partition(A, st, end);
	quicksort(A, st, pindex-1);
	quicksort(A, pindex+1, end);
}



void print_int_arr(int *arr, int N){

	int i;
	
	for(i = 0; i < N; i++){
		printf("%d ", arr[i]);
	}
	
	printf("\n\n");
}














