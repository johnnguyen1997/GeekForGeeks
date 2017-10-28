#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Turns out, this takes a lot longer than I thought.

//Basically it is a matter of building the data structure behind it 
typedef struct {
    char character;
    int freq;
} CharFreq;

typedef struct node {
    struct node* left;
    struct node* right;
    CharFreq huffman;
    int value;
} Node;

int cmpfunc (const void * a, const void * b) {
    CharFreq a1 = *(CharFreq*)a;
    CharFreq b1 = *(CharFreq*)b;
    if((b1.freq - a1.freq) != 0) {
        return (a1.freq - b1.freq);
    } else {
        return (a1.character - b1.character);
    }
}

int main()
{
	int numTests;
	int i = 0;
	scanf("%d", &numTests);
	for(i = 0; i < numTests; i++) {
	    char inputString [27];
	    scanf("%s", inputString);
	    int numNodes = (int) strlen(inputString);
	    int j;
	    int total = 0;
	    //Extract data
	    CharFreq* characters = malloc(sizeof(CharFreq) * numNodes);
	    for(j = 0; j < numNodes; j++) {
	        characters[j].character = inputString[j];
	        int temp;
	        scanf("%d", &temp);
	        characters[j].freq = temp;
	        total += temp;
	    }
	    //Sort descending
	    qsort(characters, numNodes, sizeof(CharFreq), cmpfunc);
	    
	    //Now to apply Huffman encoding
        Node* startLeft = malloc(sizeof(Node));
        startLeft->huffman = characters[0];
        startLeft->value = characters[0].freq;
        Node* startRight = malloc(sizeof(Node));
        startRight->huffman = characters[1];
        startRight->value = characters[1].freq;
	    Node* seed = malloc(sizeof(Node));
	    seed->left = startLeft;
	    seed->right = startRight;
	    seed->value = characters[1].freq + characters[0].freq;
	    total -= seed->value;
	    int index = 2;
	    while(total && (index < numNodes)) {
	        Node* root = malloc(sizeof(Node));
	        root->right = seed;
	        Node* newNode = malloc(sizeof(Node));
	        newNode->huffman = characters[index];
	        newNode->value = characters[index].freq;
	        root->left = newNode;
	        root->value = root->left->value + root->right->value;
	        total -= root->left->value;
	        seed = root;
	        index++;
	    }
	    printf("Done\n");
	}
	return 0;
}