/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
Structure of the element of the array is as
struct Height {
	int feet;
	int inches;
};
*/

//PROBLEM URL: http://practice.geeksforgeeks.org/problems/maximum-in-struct-array/1


// function must return the maximum Height
// return the height in inches
int findMax(Height arr[], int n)
{
    // Code here
    int i = 0;
    int max = 0;
    for(i = 0; i < n; i++) {
        int height = (arr[i].feet * 12) + arr[i].inches;
        if(height > max) {
            max = height;
        }
    }
    return max;
}