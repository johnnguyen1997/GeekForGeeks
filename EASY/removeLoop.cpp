/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
PROBLEM URL: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1/?ref=self
Basically you find where the loop occurs. Stop, go back and point the 
previous node to null
*/

/*The structure of linked list is the following
struct Node
{
int data;
Node* next; 
};*/
/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *node)
{
    // your code goes here
    Node* currentNode = node;
    int i = 0;
    Node** addresses = new Node*[500];
    int index = 0;
    Node* previous = NULL;
    int in = 1;
    while(currentNode != NULL && in) {
        for(i = 0; i < 500; i++) {
            if (addresses[i] == currentNode) {
                previous->next = NULL;
                in = 0;
                break;
            }
        }
        addresses[index] = currentNode;
        index++;
        previous = currentNode;
        currentNode = currentNode->next;
    }
}
