#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS_IN_BYTE 8

int largest_binarygap(char []);
void int_to_binary(int, char *);
void reverse(char *);
int atoi2(char[]);


int main(int argc, char *argv[]){
	
	int N, largest;

	N = 1041; // test number
	char binary[65]; // 64 bit safety	

	int_to_binary(N, binary);
	largest = largest_binarygap(binary);	

	printf("%s\n", binary);
	printf("largest gap: %d\n", largest);

	return 0;
}

int largest_binarygap(char binary[]){

	int i, position, largest;
 
	largest = position = -1;
	i = strlen(binary) - 1;		

	for(i; i >= 0; i--)
		if(binary[i] == '1')
			if(position == -1){
				position = i;
			}
			else {			
				largest = largest < (position - i - 1) ? position - i - 1: largest; 
				position = i;
			}			
		
	
	return largest;	
}


void int_to_binary(int n, char *binary){
		
	int i, x, size;
	
	size = sizeof(n) * BITS_IN_BYTE;

	for(i = 0, x = 1; i < size; i++, x *= 2)
		binary[i] = ( n & x ) ? '1' : '0';
	
	reverse(binary);

	return;
}


void reverse(char *arr){
	
	int i, size, swaps;
	int hold;

    size = strlen(arr) - 1; // 0 based arr
	swaps = (size % 2 == 0) ? size / 2 : (size - 1) / 2 ;
	
	for(i = 0; i < swaps; i++) {
		hold = arr[i];
		arr[i] = arr[size - i]; 
		arr[size - i] = hold;
	}
	
	return;
}


int atoi2(char s[]){
	
	int i, n;
	
	n = 0;
	for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');

	return n;


	/*	
		-> 128

		n = 0 + 1;
		n = 1;
		
		n = 10 * 1 + 2
		n = 12

		n = 10 * 12 + 8
		n = 128

		128 64 32 16 8 4 2 1

		0 	0	0	0


	*/
}
