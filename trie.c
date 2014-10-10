#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

/*use next[(trieNode->sortfactor)-(int)'a']*/
int add(char toadd,trieNode* parent){
	int index;

	if(((int)toadd - (int)'a') < 0){
		index = ((int)toadd - (int)'A');
	}
	else{
		index = ((int)toadd - (int)'a');
	}

	if(parent->next[index] == NULL){
		parent->next[index] = buildNode((char)((int)toadd + 97),1,(parent->level)+1);
	}
	else{
		parent->next[index]->count++;
	}

	return index;
}

void insert(trieNode* toinsert,trieNode* root){

}

/*To delete the whole tree:traverse to the bottom of the tree and delete each node when recursion bubbles back up
  To delete one:reassign pointers and then free memory
  To delete tree:repeatedly call delete one */
void deleteOne(trieNode* todelete,trieNode* root){ 
free(todelete);
}

void deleteTrie(trieNode* root){

}

trieNode* buildNode(char data,int isWord,int level){
	trieNode* node = (trieNode*)malloc(sizeof(trieNode));
	node->data = data;
	node->count = 1;
	node->isWord = isWord;
	node->level = level;

return node;
}

int buildTrie(char* input){
	int i = 0;
	trieNode* temp = NULL;
	root = buildNode('$',-1,-1);

	gWordCount = 0;
	temp = root;

	for(i = 0;i < (sizeof(input)/sizeof(input[0]));i++){
		if(((int)input[i]) <= 90 && ((int)input[i]) >=65){
			temp = temp->next[add(input[i],temp)];
		}
		else if(((int)input[i]) <= 122 && ((int)input[i]) >=97){
			temp = temp->next[add(input[i],temp)];
		}
		else{
			if(temp->data != '$'){
				temp->isWord = 0;
				gWordCount++;
				temp = root;
			}
		}	
	}

	return 0;
}

void printTrie(trieNode* root){

}

int traverseTrie(trieNode* root){

}
