#include <iostream>
#include <stack>
using namespace std;
struct Point {
    int position;
    char value;
};
//PROBLEM URL: http://practice.geeksforgeeks.org/problems/longest-valid-parentheses/0

//I learnt the new concept of painting to find longest substrings
//This form of painting will allow me to tackle on other subproblems hopefully.
int main() {
	int numTests;
	scanf("%d", &numTests);
	int i = 0;
	for(i = 0; i < numTests; i++) {
        //Ok we have a 10000 char limit as per specs
        char inputString[10001];
        scanf("%s", inputString);
        int count = 0;
        
        //Store the data in stack
        stack<Point> pointStack;
        int j = 0;
        while(inputString[count]) {
            count++;
        }
        //What we do is paint it as in we slowly find valid pairs
        //e.g. ()()) --> 11110
        int* paint = new int[count];
        for(j = 0; j < count; j++) {
            paint[j] = 0;
        }
        
        //Keep iterating until we go through entire stack
        for(j = 0; j < count; j++) {
            if(inputString[j] == '(') {
                //Push into stack
                Point tempPoint;
                tempPoint.value = '(';
                tempPoint.position = j;
                pointStack.push(tempPoint);
            } else if(inputString[j] == ')') {
                //We need to do some validity checking
                //Check if the stack is not empty
                if(!pointStack.empty()) {
                    //Paint the array
                    paint[j] = 1;
                    paint[pointStack.top().position] = 1;
                    pointStack.pop();
                }
            }
        }
        
        //Find the longest consecutive streak of 1's
        int currentStreak = 0;
        int maxStreak = 0;
        for(j = 0; j < count; j++) {
            if(!paint[j]) {
                currentStreak = 0;
            } else {
                currentStreak++;
                if(currentStreak >= maxStreak) {
                    maxStreak = currentStreak;
                }
            }
        }
        
        
        //Done
        printf("%d\n", maxStreak);
	}
	return 0;
}