#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//PROBLEM URL: http://practice.geeksforgeeks.org/problems/start-elements/0

//Main problem is not getting a TLE. So at least O(n) speed
//Looking at this the hard part most people would face is the possibility
//of having duplicates of max values.

//Eyeball test says O(n) speed due to creating a stack 
//with O(n) aux space. O(n) space by creating a stack from the last max
//and the end. We could reduce the space by reversing the order of the vector 
//that reads the values 

int main() {
	//code
	int numTests;
	int i;
	cin >> numTests;
	for(i = 0; i < numTests; i++) {
	    int j;
	    int arrayLength;
	    cin >> arrayLength;
	    
	    //The general idea is to use a stack
	    //If you 
	    int superStar;
	    vector<int> inputVector;
	    
	    //In general we need to know what the biggest number is
	    //That dictates the super star. Of course we have the case
	    //where there are two instances of the max number
	    int currentMax = -1;
	    int duplicate = 0;
	    for(j = 0; j < arrayLength; j++) {
	        int input;
	        cin >> input;
	        if(input >= currentMax) {
	            //We have a potential max
	            //Empty the vector
	            inputVector.clear();
	            
	            //Assume we don't have duplicate
	            duplicate = 0;
	            if(input == currentMax) {
	                //We don't have a super max if applicable
	                duplicate = 1;
	            }
	            //Change the max, trivial if duplicate
	            currentMax = input;
	            inputVector.push_back(currentMax);
	        } else {
	            //This case we just of less we just insert into vector
	            inputVector.push_back(input);
	        }
	    }
	    
	    //We should have a vector containing a max or super max (if duplicate)
	    //not there
	    
	    //Go through the entire vector and slowly pop (treat like stack)
	    int vectorLength = inputVector.size();
	    stack<int> printStack;
	    int backwardsMax = 0;
	    for(j = 0; j < vectorLength; j++) {
	        //Go backwards and push into another stack to print properly
	        if(inputVector.back() > backwardsMax) {
	            //So the back is larger than the current max,
	            //push it in the stack and treat as new
	            //We basically abuse the fact that we only need to
	            //check one number.
	            
	            //e.g. if we get  7 2 3 5 2 1. To insert 1 we check with 0
	            //To insert 2 we check with 1. To insert 5 we check with 2.
	            //To insert 3 with check with 5. To insert 2 we check with 5.
	            //To insert 7 we check with 5.
	            printStack.push(inputVector.back());
	            backwardsMax = inputVector.back();
	        }
	        inputVector.pop_back();
	    }
	    
	    
	    //Now we print the stack properly
	    int length = printStack.size();
	    for(j = 0; j < length; j++) {
	        printf("%d ", printStack.top());
	        printStack.pop();
	        
	    }
	    printf("\n");
	    if(duplicate == 0) {
	        printf("%d\n", currentMax);
	    } else {
	        printf("-1\n");
	    }
	    
	}
	return 0;
}