#include <stdio.h>
#include <stdlib.h>
//Problem URL: http://practice.geeksforgeeks.org/problems/left-rotate-matrix-k-times/0
//X-Y are the matrix dimensions
//Problem is that it doesn't free up the memory
int** rotateMatrix(int** matrix, int x, int y) {
    //Create a matrix
    int** outputMatrix = malloc(sizeof(int*) * x);
    int i = 0;
    int j = 0;
    for(i = 0; i < x; i++) {
        outputMatrix[i] = malloc(sizeof(int) * y);
    }
    
    //Do the matrix rotate
    for(i = 0; i < x; i ++) {
        for(j = 0; j < y; j++) {
            int element= matrix[i][j];
            int nextJ;
            if(j == 0) {
                nextJ = y - 1;
            } else {
                nextJ = j - 1;
            }
            outputMatrix[i][nextJ] = element;
        }
    }


    return outputMatrix;
}

int main() {
	//code
	int numTests;
	scanf("%d", &numTests);
	
	int i = 0;
	for(i = 0; i < numTests; i++) {
	    //Read the matrix
	    int m = 0;
	    scanf("%d", &m);
	    int n = 0;
	    scanf("%d", &n);
	    int** matrix = malloc(sizeof(int*) * m);
	    int j = 0;
	    for(j = 0; j < m; j++) {
	        matrix[j] = malloc(sizeof(int) * n);
	    }
	    
	    int k = 0;
	    scanf("%d", &k);
	    int a;
	    int b;
	    
	    for(a = 0; a < m; a++) {
	        for(b = 0; b < n; b++) {
	           int hold;
	           scanf("%d", &hold);
	           matrix[a][b] = hold;
	        }
	    }
	    int numRotations = k;
	    for(k = 0; k < numRotations; k++) {
	        matrix = rotateMatrix(matrix, m, n);
	    }
	    for(a = 0; a < m; a++) {
	        for(b = 0; b < n; b++) {
	            printf("%d ", matrix[a][b]);
	        }
	    }
	    printf("\n");
	}
	
	return 0;
}