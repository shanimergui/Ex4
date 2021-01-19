#ifndef _TREEFUNCTIONS_H_
#define _TREEFUNCTIONS_H_





// a constant definition 

#define NUM_LETTERS ((int)26) 

typedef enum { FALSE = 0, TRUE = 1 } boolean;

typedef struct node {

	char letter;
	long unsigned int count;
	struct node* children[NUM_LETTERS];

} node;


// a function prototype 

node* newNode();
void buildTree(node* head);
node* addword(node* pointNode,char character);
int bigWordLength(node* n, int counter);
void freeLevelsOnTree(node* head);
void printWord(node* head,char strWord[], int levelTree);
void printWordReverse(node* head,char strWord[], int levelTree);











#endif
