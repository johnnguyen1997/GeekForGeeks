/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below*/
int findExtra(int a[],int b[],int n)
{
 //add code here.
 int i = 0;
 for(i = 0; i < n; i++) {
     if(!(a[i] == b[i])) {
         return i;
     }
 }
}