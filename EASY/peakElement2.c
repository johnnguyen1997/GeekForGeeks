#include <stdio.h>
#include <stdlib.h>

//Could make it quicker by reading as we goto
//PROBLEM URL: http://practice.geeksforgeeks.org/problems/find-the-highest-number/0
int main() {
	//code
	int numTests;
	scanf("%d", &numTests);
	int i = 0;
	for(i = 0; i < numTests; i++) {
	    //Read the array length
	    int arrayLength;
	    scanf("%d", &arrayLength);
	    
	    int* inputArray = malloc(sizeof(int) * arrayLength);
	    int j = 0;
	    int prev = -1;
	    int current = 0;
	    int next;
	    for(j = 0; j < arrayLength; j++) {
	        int input;
	        scanf("%d", &input);
	        inputArray[j] = input;
	    }
	    
	    int peak = -1;
	    for(j = 1; j < arrayLength - 1; j++) {
	        prev = inputArray[j - 1];
	        current = inputArray[j];
	        next = inputArray[j + 1];
	        
	   
            if((current > prev) && (current > next)) {
                peak = current;
            }
	    }
	    
	    if(peak == -1) {
	        //Peak is at the last unit
	        peak = inputArray[arrayLength - 1];
	    }
	    printf("%d\n", peak);
	}
	return 0;
}