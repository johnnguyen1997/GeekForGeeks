#include <stdio.h>

#include <stdlib.h>


//PROBLEM URL: http://practice.geeksforgeeks.org/problems/next-larger-element/0
int MAXSIZE = 8;       
int stack[1000];     
int top = -1;            

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}

int pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int push(int data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}

int main() {
	//code
	int numTests;
	scanf("%d", &numTests);
	int i = 0;
	int size = 0;
	int j = 0;
	int count = 0;
	for(i = 0; i < numTests; i++) {
	    scanf("%d", &size);
	    count = 0;
	    MAXSIZE = size;
	    int* greater = malloc(sizeof(int) * size);
	    int* inputs = malloc(sizeof(int) * size);
	    int input = 0;
	    for(j = 0; j < size; j++) {
	        scanf("%d", &input);
	        inputs[j] = input;
	        greater[j] = -1;
	    }
	    int k = 0;
	    for(j = 0; j < size; j++) {
	        for(k = j; k < size; k++) {
	            if(inputs[j] < inputs[k]) {
	                greater[j] = inputs[k];
	                break;
	            }
	        }
	    }
	    for(j = 0; j < size; j++) {
	        printf("%d", greater[j]);
	        if(j != (size - 1)) {
	            printf(" ");
	        } else {
	            printf("\n");
	        }
	        
	    }
	}
	return 0;
}