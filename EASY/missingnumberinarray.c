#include <stdio.h>
#include <stdlib.h>
int main() {
	int numTests;
	scanf("%d", &numTests);
	
	int i = 0;
	for(i = 0; i < numTests; i++) {
	    int size;
	    scanf("%d", &size);
	    //Find the 1
	    int* outcomes = malloc(sizeof(int) * size);
	    int j = 0;
	    for(j = 0; j < size; j++) {
	        outcomes[j] = 0;
	    }
	    for(j = 0; j < size - 1; j++) {
            int incomingInt;
            scanf("%d", &incomingInt);
            //Accomodate for 0-index
            outcomes[incomingInt - 1] = 1;
	    }
	    
	    for(j = 0; j < size; j++) {
	        if(outcomes[j] == 0) {
	            printf("%d\n", j + 1);
	        }
	    }
	    
	}
	
	
	return 0;
}