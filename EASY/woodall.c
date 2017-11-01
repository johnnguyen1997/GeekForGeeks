#include<stdio.h>

//The really trivial solution would be to calculated as many woodall numbers
//as possible and check for a match. Stop if we go over.

//Of course not what we want

//PROBLEM URL: http://practice.geeksforgeeks.org/problems/woodall-number/0

//Really easy, just follow the rules
int main()
{
	int numTests;
	int i;
	scanf("%d", &numTests);
	for(i = 0; i < numTests; i++) {
	    int input;
	    scanf("%d", &input);
	    
	    //I mean we could check if odd and remove the even cases quickly
	    if(input % 2) {
	        //OK possibly Woodal
	        input++;
	        //Basically we have n * 2^n left after adding one
	        
	        //Rewrite as x * 2^y. We keep dividing by 2 until we reach
	        //an odd or equality
	        int count = 0;
	        while(1) {
	            if((input % 2) == 0) {
	                //Increment count and divide
	                count++;
	                input = input/2;
	            } else {
	                //Case 1: we reach an odd
	                //Ok check if the results match
	                if(count == input) {
	                    printf("1\n");
	                } else {
	                    printf("0\n");
	                }
	                break;
	            }
	            if(count == input) {
	                printf("1\n");
	                break;
	            }
	        }
	        
	    } else {
	        //Even
	        printf("0\n");
	    }
	}
	return 0;
}