#include <iostream>
using namespace std;

//PROBLEM URL: http://practice.geeksforgeeks.org/problems/stickler-theif/0

//Not difficult if you understand dynamic programming. Since this was 
//my first time seeing this. It was tough. Used a users solution.

//Clearly a O(n) solution using O(n) space

int main() {
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        int A[N];
        for(int i = 0 ; i < N ; i++){
            cin >> A[i];
        }
        //Dynamic programming solution
        int dp[N];
        
        //Clearly 0-based index would be the first element
        dp[0] = A[0];
        
        //1-based index would be the max between 0 and 1 index
        dp[1] = max(A[0] , A[1]);
        
        //Comparison of hypotheticals
        int test1;
        int test2;
        
        //Iterate through the array
        for(int i = 2 ; i < N ; i++){
            test1 = A[i] + dp[i-2]; // Current element included
            test2 = dp[i-1]; //Current element not needed
            
            //Basically the solution is based on whether or not 
            //we actually need to add the next term or not.
            dp[i] = max(test1 , test2);
            
        }
        cout << dp[N-1] << endl;
    }
    return 0;
}