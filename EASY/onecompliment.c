#include <stdio.h>
#include <math.h>

//Problem URL: http://practice.geeksforgeeks.org/problems/ones-complement/0#ExpectOP

//In short, xor all the bits with 1's of the highest power
int main() {
	int numTests;
	scanf("%d", &numTests);
	
	int i;
	for(i = 0; i < numTests; i++) {
	    int input;
	    scanf("%d", &input);
	    int numBits = floor(log2(input)) + 1;
	    int result = ((1 << numBits) - 1) ^ input;
	    
	    
	    
	    printf("%d\n", result);
	}
	return 0;
}