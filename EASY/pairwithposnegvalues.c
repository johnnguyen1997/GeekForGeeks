#include<stdio.h>
#include<stdlib.h>

//PROBLEM URL: http://practice.geeksforgeeks.org/problems/pairs-with-positive-negative-values/0

//Basically sort the array by absolute values
//Once sorted check the next value and see if it a pair

//In case of triples unknown effect

//Expected complexity (O(nlogn)). Quicksort is the main reason
//O(n) to go through entire array
int cmpfunc (const void * a, const void * b) {
    int a1 = *(int*)a;
    int b1 = *(int*)b;
    
    if(a1 < 0) {
        a1 = a1 * -1;
    }
    
    if(b1 < 0) {
        b1 = b1 * -1;
    }
    
   return (a1 - b1 );
}

int main()
{
	int numTests;
	int i;
	scanf("%d", &numTests);
	for(i = 0; i < numTests; i++) {
	    int j;
	    int arrayLength;
	    scanf("%d", &arrayLength);
	    int pairNum = 0;
	    int* inputArray = malloc(sizeof(int) * arrayLength);
	    int negatives = 0;
	    int positives = 0;
	    for(j = 0; j < arrayLength; j++) {
	        int input;
	        scanf("%d", &input);
	        inputArray[j] = input;
	    }
	    
	    //Sort it based on absolutes
	    qsort(inputArray, arrayLength, sizeof(int), cmpfunc);
	    
	    //Go through the sorted array
	    
	    for(j = 0; j < (arrayLength - 1); j++) {
	        if(inputArray[j] == (-1 * inputArray[j + 1])) {
	            //Match
	            pairNum++;
	            if(inputArray[j] > 0) {
	                printf("%d %d", inputArray[j + 1], inputArray[j]);
	            } else {
	                printf("%d %d", inputArray[j], inputArray[j + 1]);
	            }
	            j++;
	            if(j < arrayLength) {
	                printf(" ");
	            }
	        }
	    }
	    if(pairNum == 0) {
	        printf("0\n");
	    } else {
	        printf("\n");
	    }
	    
	    
	}
	
	return 0;
}