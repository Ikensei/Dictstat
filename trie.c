#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

/*use next[(trieNode->sortfactor)-(int)'a']*/
void add(trieNode* toadd,trieNode* root){
	
}

void insert(trieNode* toinsert,trieNode* root){

}

/*To delete the whole tree:traverse to the bottom of the tree and delete each node when recursion bubbles back up
  To delete one:reassign pointers and then free memory
  To delete tree:repeatedly call delete one */
void deleteOne(trieNode* todelete,trieNode* root){ 
free(todelete);
}

void deleteTree(trieNode* root){

}

trieNode* buildNode(char data,unsigned char isWord,int level){
	trieNode* node = (trieNode*)malloc(sizeof(trieNode));
	node->data = data;
	node->count = 1;
	node->isWord = isWord;
	node->level = level;
	/*node->next;*/

return node;
}

trieNode* buildTree(char* input){

}

void printTrie(trieNode* root){

}
