#include<stdio.h>

//O(n) solution. Example of bit manipulation. In short. a xor a xor b = 0 xor b
//which is equal to b. Also other stuff such as associativity and commutitivity
//of xor

//PROBLEM URL: http://practice.geeksforgeeks.org/problems/single-number/0

int main()
{
	int numTests;
	int i;
	scanf("%d", &numTests);
	for(i = 0; i < numTests; i++) {
	    int numElements;
	    scanf("%d", &numElements);
	    int j;
	    
	    int outcome = 0;
	    
	    for(j = 0; j < numElements; j++) {
	        int temp;
	        scanf("%d", &temp);
	        outcome ^= temp;
	    }
	    
	    printf("%d\n", outcome);
	}
	return 0;
}