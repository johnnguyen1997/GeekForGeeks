#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//PROBLEM URL: http://practice.geeksforgeeks.org/problems/maximum-index/0

//TODO: Show its complexity

//The goal is O(n) time. O(n^2) is trivial using double for-loop of
//O(n) and O(n)

/*Notes: The main logic is to sweep the array twice to find min and search values.
In the first example, we don't care about large values.

In the example 3 5 4 2. We don't care about 5 or 4 because if there is a number
larger than 4, it's larger than 3.

The second sweep is to check for latest value which is larger than or
equal to the first/0 index.

The very worst case is something like 5 4 3 2 1. Where the largest value 
happens to be the first value.

The left sweep is takes O(n). The right sweep is also O(n). Yet the worst case
when we combine the two sweeps
*/

struct Point {
    int position;
    int value;
};

int main() {
	int numTests;
	scanf("%d", &numTests);
	
	int i = 0;
	for(i = 0; i < numTests; i++) {
	    //Extracting the tests
	    int arraySize;
	    scanf("%d", &arraySize);
	    int j = 0;
	    vector<int> inputVector;
	    for(j = 0; j < arraySize; j++) {
	        int tempNum;
	        scanf("%d", &tempNum);
	        inputVector.push_back(tempNum);
	    }
	    
	    //Actual logic
	    int maxIndex = 0;
	    int minValue = 9999;
	    int maxValue = 0;
	    vector<Point> minVectors;
	    vector<int> maxCheckPos;
	    for(j = 0; j < arraySize; j++) {
	        if(inputVector[j] < minValue) {
	            minValue = inputVector[j];
	            Point tempPoint;
	            tempPoint.value = minValue;
	            tempPoint.position = j;
	            minVectors.push_back(tempPoint);
	        }
	        //Find the max
	        if(inputVector[j] > maxValue) {
	            maxValue = inputVector[j];
	        }
	    }
	    //It is guaranteed that the first element of this vector is
	    //the largest
	    int maxCheck = inputVector[0];
	    int finalIndex = 0;
	    //First we check the first instance the max is met
	    for(j = 0; j < arraySize; j++) {
	        if(inputVector[j] >= maxCheck) {
	            finalIndex = j;
	            break;
	        }
	    }
	    
	    //Ok now we iterate through our minValues and compare with our maxes
	    int k = 0;
	    int max = 0;
	    for(j = 0; j < minVectors.size(); j++) {
	        for(k = finalIndex; k < arraySize; k++) {
	            //Check
	            if(minVectors[j].value <= inputVector[k]) {
	                //Calc difference
	                if(max < (k - minVectors[j].position)) {
	                    max = k - minVectors[j].position;
	                }
	            }
	        }
	    }
	    printf("%d\n", max);
	}
	return 0;
}