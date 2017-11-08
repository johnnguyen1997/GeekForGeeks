/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//PROBLEM URL: http://practice.geeksforgeeks.org/problems/peak-element/1
//Trivial solution. Check go through the entire array and return 
//if it a peak. Check one side if corner or check both if not.



/* The function should return the index of any
   peak element present in the array */
int peak(int arr[], int n)
{
   // Your code here
   int i = 0;
   for(i = 0; i < n; i++) {
       //Edge cases
       if(i == 0) {
           if(arr[i] >= arr[i + 1]) {
               return i;
           }
       } else if(i >= (n - 1)) {
           if(arr[i] >= arr[i - 1]) {
               return i;
           }
       } else {
           if((arr[i] >= arr[i - 1]) && (arr[i] >= arr[i + 1])) {
               return i;
           }
       }
   }
}