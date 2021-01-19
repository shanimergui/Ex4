#include <stdio.h>
#include <string.h>
#include "treeFunctions.h"
#include <stdlib.h>





int main(int argc, char* argv[]) {

	node* head=newNode(); 
	buildTree(head);  
        int biggestWordLength=bigWordLength(head, 0) + 1;
        char* word = (char*)malloc(sizeof(char)*biggestWordLength);

	if( (argc==2) && (strcmp(argv[1],"r")==0) )
        {
                printWordReverse(head,word,0);}

	else  if(argc==1) {
		printWord(head,word,0);
	}


        free(word);
	freeLevelsOnTree(head);


	return 0;
}

