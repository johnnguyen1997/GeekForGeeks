/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
  Reverse a linked list
  The input list will have at least one element  
  Return pointer to head of reverse linked list 
  Node is defined as 
  struct node
  {
     int data;
     struct Node *next;
  }
*/

//PROBLEM URL: http://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
struct node *reverse (struct node *head, int k)
{ 
    struct node* start = head;
    int connecting = 0;
    struct node** reverseArray = malloc(sizeof(struct node*) * k);
    int firstReverse = 0;
    int i = 0;
    int j = 0;
    while(head != NULL) {
        //Looping until we reach null
        
        //We need to reverse if the next next instance is null
        if(i == k)  {
            //Reverse
          
            for(j = 0; j < (k/ 2); j++) {
                int temp = reverseArray[k - 1 - j]->data;
                reverseArray[k - 1 - j]->data = reverseArray[j]->data;
                reverseArray[j]->data = temp;
            }
            
            i = 0;
        }
        
        //Increment and store
        reverseArray[i] = head;
        
        head = head->next;
        
        ++i;
    }
    
    //Test for case in which we don't have a nice i
    //Looping until we reach null
    
    //We need to reverse if the next next instance is null
    if(i)  {
        //Reverse
        for(j = 0; j < (i/ 2); j++) {
            int temp = reverseArray[i - 1 - j]->data;
            reverseArray[i - 1 - j]->data = reverseArray[j]->data;
            reverseArray[j]->data = temp;
        }
        
    }
            
    return start;
}
