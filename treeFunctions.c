#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "treeFunctions.h"
#include <stdlib.h>


node* newNode() {
     
    node* pointerNode = NULL;             
    pointerNode = (node *)malloc(sizeof(node));        //allocate memory from the heap
  
    if (pointerNode) 
    { 
        pointerNode->count = 0; 
    
      int i;                                 //declaration of variable
        for(i=0; i<26;i++){
            pointerNode->children[i] = NULL;}

    } 

    else{
        printf("error-malloc not allocate memory");
        return NULL;
    }

    return pointerNode; 
} 



void buildTree(node* head)               //start build the tree from the word
{

    char character;                         //declaration of variable
    node* pointNode = head;
   
   do{

        character = getchar();
     
 
        if(character == EOF)
        {
            if (pointNode){
                pointNode->count++;}
            return;
        }


        character = tolower(character); //Turns a big letter into a small letter lib <ctype.h>



        if( ! (  (character >= 'a' && character <= 'z')||(character >= 'A' && character <= 'Z')||(character ==' ' ||character =='\t' ||character=='\n' ) ) ){

              continue;}


        
        if (character=='\n' || character==' ' || character=='\t')
        {
            
            if ( (pointNode!=NULL) && (pointNode != head)  )
            {
                pointNode->count++;
                pointNode= NULL;
            }
            
            continue;
        }

        if(pointNode ==NULL){
             pointNode = head;}  

     
        pointNode = addword(pointNode, character);
        

   }while(character!=EOF);



}




node* addword(node* pointNode,char character){        //add letter to the tree

    int i = (((int)character)-((int)'a'))  ;        //declaration variable and calculate the place of the index

    if( (pointNode->children[i])==NULL ){
        pointNode->children[i] = newNode();
        pointNode->children[i]->letter=character; 
    }

    pointNode=pointNode->children[i]; 

    return pointNode;

}





void freeLevelsOnTree(node* head){                       //free function

	if(head == NULL)
		return;
	for(int i = 0; i<NUM_LETTERS; i++){
		freeLevelsOnTree(head->children[i]);
	}
	free(head);
	return;
}





int bigWordLength(node* n,int counter){                        //check size of biglength word

    int i;                                                     //declaration of variable
    int length = counter;

    for( i=0; i<NUM_LETTERS; i++ )
    {
        if(n->children[i]!=NULL)
        {
            int length2 = bigWordLength(n->children[i], counter + 1);

            if(length2>length)
            {
              length = length2;
            }

        }
    }

    return length;

}




void printWord(node* head,char strWord[],int levelTree){

    node* nPointer = head;

    if (nPointer == NULL){
       return;}

    if (nPointer->count > 0){
        strWord[levelTree] = '\0';
        printf("%s\t %ld \n",strWord,nPointer->count);}
    
     int i;                                                         //declaration of variable
    for(i = 0; i<NUM_LETTERS; i++)                       
    {

        if(nPointer->children[i] != NULL)
        {
            strWord[levelTree]=nPointer->children[i]->letter;
            printWord(nPointer->children[i],strWord,levelTree+1);
        }
    }
}




void printWordReverse(node* head,char strWord[], int levelTree){

    int i;                                        //declaration of variable
    node* nPointer2 = head;

    if(nPointer2 == NULL){
          return;}

    if(nPointer2->count > 0)
  {
     for(i=NUM_LETTERS-1; i>= 0; i--)
      {
        if(nPointer2->children[i]!= NULL)
         {
            strWord[levelTree] = nPointer2->children[i]->letter;
            printWordReverse(nPointer2->children[i], strWord, levelTree + 1);
            
         }
        
      }
       strWord[levelTree] = '\0';
       printf("%s\t %ld \n",strWord,nPointer2->count); 

  }
    
 else{

    for(i = NUM_LETTERS-1; i >= 0; i--)
      {
        if(nPointer2->children[i]!= NULL)
           {
            strWord[levelTree] = nPointer2->children[i]->letter;
            printWordReverse(nPointer2->children[i], strWord, levelTree + 1);
           }
      }


     }




}


