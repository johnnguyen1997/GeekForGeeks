#include<stdio.h>
#include<stdlib.h>

//Display of array is a bit sloppy
//PROBLEM URL: http://practice.geeksforgeeks.org/problems/even-and-odd-elements-at-even-and-odd-positions/0


int main()
{
	//code
	int numTests;
	int i;
	scanf("%d", &numTests);
	for(i = 0; i < numTests; i++) {
	    int arrayLength;
	    scanf("%d", &arrayLength);
	    
	    int* oddArray = malloc(sizeof(int) * arrayLength);
	    int* evenArray = malloc(sizeof(int) * arrayLength);
	    
	    int j = 0;
	    int oddIndex = 0;
	    int evenIndex = 0;
	    for(j = 0; j < arrayLength; j++) {
	        int input;
	        scanf("%d", &input);
	        
	        if(input % 2) {
	            //Odd
	            oddArray[oddIndex] =  input;
	            oddIndex++;
	        } else {
	            //Even
	            evenArray[evenIndex] = input;
	            evenIndex++;
	        }
	    }
	    int oddTrav = 0;
	    int evenTrav = 0;
	    //Arrays filled, iterate through the array
	    int output;
	    for(j = 0; j < arrayLength; j++) {
	        //Check for index
	        if(j % 2) {
	            //Odd
	            if(oddTrav < oddIndex) {
	                output = oddArray[oddTrav];
	                oddTrav++;
	            } else {
	                output = evenArray[evenTrav];
	                evenTrav++;
	            }
	        } else {
	            //Even
	            if(evenTrav < evenIndex) {
	                output = evenArray[evenTrav];
	                evenTrav++;
	            } else {
	                output = oddArray[oddTrav];
	                oddTrav++;
	            }
	        }
	        
	        //Got the output, print well
	        if(j == (arrayLength - 1)) {
	            printf("%d\n", output);
	        } else {
	            printf("%d ", output);
	        }
	    }
	}
	return 0;
}