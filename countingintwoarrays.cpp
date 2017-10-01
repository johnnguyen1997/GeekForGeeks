/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
//PROBLEM URL: http://practice.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1
void countEleLessThanOrEqual(int arr1[], int arr2[], 
                             int m, int n)
{
//Your code goes here

    //Basically double for loop
    int i = 0;
    int j = 0;
    int count;
    for(i = 0; i < m; i++) {
        count = 0;
        for(j = 0; j < n; j++) {
            if(arr1[i] >= arr2[j]) {
                count++;
            }
        }
        printf("%d ", count);
    }
}