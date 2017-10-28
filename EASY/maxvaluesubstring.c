#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Basically C sucks with string handling. I would prefer have a function
//that could easily find substring for me.
//PROBLEM URL: http://practice.geeksforgeeks.org/problems/extract-maximum/0

//General gist is to just parse each character and check if they are a number
//Then create the number by grabbing the substring

//O(n) time
//O(n) space
int main()
{
	int numTests;
	int i = 0;
	scanf("%d", &numTests);
	for(i = 0; i < numTests; i++) {
	    //100 length strings
	    char inputString [101];
	    scanf("%s", inputString);
	    int length = (int) strlen(inputString);
	    int j = 0;
	    int index = 0;
	    int endIndex = 0;
	    int max = -1;
	    char tempString [101];
	    for(j = 0; j < length; j++) {
	        if((inputString[j] >= '0') && (inputString[j] <= '9')) {
	            //Valid character
	            tempString[endIndex] = inputString[j];
	            endIndex++;
	            if(j == (length - 1)) {
	                tempString[endIndex] = 0;
	                int value = atoi(tempString);
	                if(value > max) {
	                    max = value;
	                }
	            }
	        } else {
	            //No good, check the value
	            //Terminate
	            tempString[endIndex] = 0;
	            int value = atoi(tempString);
	            if(value > max) {
	                max = value;
	            }
	            endIndex = 0;
	        }
	    }
	    //Case in which we are last character
	    printf("%d\n", max);
	}
	return 0;
}