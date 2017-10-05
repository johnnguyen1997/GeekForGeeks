/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Node structure  used in the program
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
}; */
/*  Function which returns the  root of 
    the flattened linked list. */
//Don't really like this method. Could probably search a bit smarter
//PROBLEM URL: http://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
Node *flatten(Node *root)
{
   //One approach is to just grab all the elements and then sort them which is fine I guess
    Node* currentNode = root;
    Node* currentBottom = root->bottom;
    //Start the movement
    vector<int> totalVector;
    while(currentNode != NULL) {
        //Push the selected node
        totalVector.push_back(currentNode->data);
        while(currentBottom != NULL) {
            totalVector.push_back(currentBottom->data);
            currentBottom = currentBottom->bottom;
        }
        
        //Go to next node
        currentNode = currentNode->next;
        
        //Change the bottom
        if(currentNode != NULL) {
            currentBottom = currentNode->bottom;
        }
    }
    //Sort the vector
    sort(totalVector.begin(), totalVector.end());
    
    //Create new root
    Node* head = (Node*) malloc(sizeof(Node));
    Node* tempRoot = head;
    int i = 0;
    for(i = 0; i < totalVector.size(); i++) {
        tempRoot->data = totalVector[i];
        if(i != (totalVector.size() - 1)) {
            Node* newRoot =  (Node*) malloc(sizeof(Node));
            tempRoot->bottom = newRoot;
            tempRoot = newRoot;  
        } else {
            tempRoot->bottom = NULL;
        }
    }
    return head;
}