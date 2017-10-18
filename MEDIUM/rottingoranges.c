#include<stdio.h>
#include<stdlib.h>

//People thought this problem is a bit hard to be called easy
//I agree because of recursion

//Logic was alright but probably not clean
//Finding impossible solutions is basically rotting until no changes made
//and then checking for a fresh orange. Similar logic with finding a full
//infection.

//Solution is slow though

//PROBLEM URL: http://practice.geeksforgeeks.org/problems/rotten-oranges/0


int main()
{
	//code
	int numTests;
	scanf("%d", &numTests);
	int i = 0;
	for(i = 0; i < numTests; i++) {
	    int row;
	    int col;
	    int j;
	    for(j = 0; j < 2; j++) {
	        if(j) {
	            scanf("%d", &col);
	        } else {
	            scanf("%d", &row);
	        }
	    }
	    
	    int** matrix = malloc(sizeof(int*) * row);
	    for(j = 0; j < row; j++) {
	        matrix[j] = malloc(sizeof(int) * col);
	    }
	    
	    int k = 0;
	    int input;
	    for(j = 0; j < row; j++) {
	        for(k = 0; k < col; k++) {
	            scanf("%d", &input);
	            matrix[j][k] = input;
	        }
	    }
	    
	    //Matrix done. Now we need to implement rot logic
	    //Be careful of rotting too quickly
	    
	    //The general logic is find all the 1's rot the guys next to it
	    //if possible and rinse and repeat.
	    
	    //Checking if it's done is based on whether or not
	    
	    //Probably a lot easier to use functions but whatever
	    int timeTaken = 0;
	    while(1) {
	        int change = 0;
	        for(j = 0; j < row; j++) {
	            for(k = 0; k < col; k++) {
	                //Check the cell
	                if(matrix[j][k] == 2) {
	                    //It's a rotting cell
	                    if((j < (row - 1)) && (matrix[j + 1][k] == 1)) {
	                        matrix[j + 1][k] = 3;
	                        change = 1;
	                    }
	                    
	                    if((j > 0) && (matrix[j - 1][k] == 1)) {
	                        matrix[j - 1][k] = 3;
	                        change = 1;
	                    }
	                    
	                    if((k < (col - 1)) && (matrix[j][k + 1] == 1)) {
	                        matrix[j][k + 1] = 3;
	                        change = 1;
	                    }
	                    
	                    if((k > 0) && (matrix[j][k - 1] == 1)) {
	                        matrix[j][k - 1] = 3;
	                        change = 1;
	                    }
	                }
	            }
	        }
	        if(change) {
	            //Increase time, update matrix
	            timeTaken++;
	            for(j = 0; j < row; j++) {
	                for(k = 0; k < col; k++) {
	                    if(matrix[j][k] == 3) {
	                        matrix[j][k] = 2;
	                    }
	                }
	            }
	        } else {
	            //No change
	            //Check for a fresh one
	            int possible = 1;
	            for(j = 0; j < row; j++) {
	                for(k = 0; k < col; k++) {
	                    if(matrix[j][k] == 1) {
	                        possible = 0;
	                    }
	                }
	            }
	            
	            if(possible) {
	                //Then tell time taken
	                printf("%d\n", timeTaken);
	            } else {
	                printf("%d\n", -1);
	            }
	            break;    
	        }
	    }
	    
	}
	
	return 0;
}