/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/

//PROBLEM URL: http://practice.geeksforgeeks.org/problems/stack-using-two-queues/1


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */
/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
        //Case where q1 is empty
        if(q1.empty()) {
            q1.push(x);
        } else {
            //Put in q2 and then funnel q1 in it then
            //put it back into q1
            if(q2.empty()) {
                q2.push(x);
                while(!q1.empty()) {
                    q2.push(q1.front());
                    q1.pop();
                }
                while(!q2.empty()) {
                    q1.push(q2.front());
                    q2.pop();
                }
            }
        }
}
/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    if(q1.empty()) {
        return -1;
    } else {
        int x = q1.front();
        q1.pop();
        return x;
    }
}
