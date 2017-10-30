#include<stdio.h>
#include<stdlib.h>

//PROBLEM URL: http://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem/0

//From my point of view, the main challenge is sorting an array by using
//another array. Can't compare with itself

//We could use some sort of quick sort where you simply use a random element
//from the bolts and then do your partitioning with the nuts and print out
//the array twice. Bad question in my opinion

//Current solution O(n^2)
int main()
{
	int numTests;
	int i;
	scanf("%d", &numTests);
	for(i = 0; i < numTests; i++) {
	    int numElements;
	    scanf("%d", &numElements);
	    int j;
	    char* nuts = malloc(sizeof(char) * numElements);
	    char* bolts = malloc(sizeof(char) * numElements);
	    for(j = 0; j < numElements; j++) {
	        char temp;
	        scanf("%c", &temp);
	        if(temp == '\n' || temp == ' ') {
	            j--;
	        } else {
	            nuts[j] = temp;
	        }
	    }
	    
	    for(j = 0; j < numElements; j++) {
	        char temp;
	        scanf("%c", &temp);
	        if(temp == '\n' || temp == ' ') {
	            j--;
	        } else {
	            bolts[j] = temp;
	        }
	    }
	    
	    //It's basically sorting an array based on the values of another
	    //I mean the naive solution is to just create an array. Find a
	    //nut's rank with respect to a bolt and so on...
			int k = 0;
			char* ordered = malloc(sizeof(char) * numElements);
			for(j = 0; j < numElements; j++) {
				int rank = 0;
				for(k = 0; k < numElements; k++) {
					if(nuts[j] > bolts[k]) {
						rank++;
					}
				}
				ordered[rank] = nuts[j];
			}
			//Print out the output
			for(j = 0; j < numElements; j++) {
				printf("%c", ordered[j]);
				if(j < (numElements - 1)) {
					printf(" ");
				}
			}
			printf("\n");
			//Print out the output
			for(j = 0; j < numElements; j++) {
				printf("%c", ordered[j]);
				if(j < (numElements - 1)) {
					printf(" ");
				}
			}
			printf("\n");
		}
		return 0;
	}