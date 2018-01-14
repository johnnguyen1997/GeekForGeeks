// PROBLEM URL: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0

//Overall not too difficult. Basically a O(w) space problem in O(wi) time
//where w is the weight and i is the number of items

//A more challenging variation would be if we only had unique items

#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int value;
    int weight;
} item;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
	int i;
	int numTests;
	scanf("%d", &numTests);
	for(i = 0; i < numTests; i++) {
	    int maxWeight;
	    int numItems;
	    scanf("%d", &numItems);
	    scanf("%d", &maxWeight);
	    int j = 0;
	    item* itemList = malloc(sizeof(item) * numItems);
	    for(j = 0; j < numItems; j++) {
	        int inputValue;
	        scanf("%d", &inputValue);
	        itemList[j].value = inputValue;
	    }
	    for(j = 0; j < numItems; j++) {
	        int inputWeight;
	        scanf("%d", &inputWeight);
	        itemList[j].weight = inputWeight;
	    }
	    
	    //Got everything, now implement logic
	    
	    //Clearly this is a knapsack DP problem.
	    //E.g. weight of 15
	    /* We create an array w of length 15
	     * where w[0] is the best solution for for weight = 0
	     * w[1] is best solution at 1. Etc.
	     * Of course we don't bother with w[16]
	     */
	    int* bestValues = malloc(sizeof(int) * (maxWeight + 1));
	    for(j = 0; j < (maxWeight + 1); j++) {
	        bestValues[j] = 0;
	    }
	    
	    //Now do the check
	    int k = 0;
	    for(j = 0; j < maxWeight; j++) {
	        int bestResult = bestValues[j];
	        for(k = 0; k < numItems; k++) {
	            //Check the weights
	            int inputWeight = itemList[k].weight;
	            if((inputWeight + j) <= maxWeight) {
	                //Good  to go
	                bestValues[j + inputWeight] =
	                    max(bestValues[j + inputWeight], 
	                        bestValues[j] +itemList[k].value);
	            }
	        }
	    }
	    printf("%d\n", bestValues[maxWeight]);
	}
	return 0;
}