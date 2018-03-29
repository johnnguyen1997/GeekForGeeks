/*
PROBLEM URL: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//function Template for C++
/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
  }
*/
/*
 * Overall not too tough. The trick is knowing to point the head's next
 * to NULL. Basically grab the current node's details and point it's next 
 * to the previous node and then go into the other 'next' node.
 */ 


// Should reverse list and return new head.
Node* reverse(Node *head)
{
    Node* currentNode = head;
    Node* prevNode = NULL;
    while(currentNode != NULL) {
        Node* nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    return prevNode;
}