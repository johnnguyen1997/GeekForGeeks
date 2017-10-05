/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/

//PROBLEM URL: http://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1
/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */
/* The method push to push element into the queue */
void StackQueue :: push(int x)
 {
        //We need to do a little bit of tinkering
        //Lets assume ethat s1 is stacked in the order we liked
        //What we need to do is keep popping s1 and store into s2
        //then store the element we need in s2
        //Then pop back into s1
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(x);
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
 }
/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
        //Pop the s1
        if(s1.empty()) {
            return -1;
        } else {
            int x = s1.top();
            s1.pop();
            return x;
        }
}
