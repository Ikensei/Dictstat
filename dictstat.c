#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trie.h"
#include "dictstat.h"


int main(int argc,char** argv){
	FILE* dictpoint = NULL;
	FILE* statpoint = NULL;
	root = NULL;

	if(argc < 3){
		fprintf(stderr, "invalid input\n");
		return 1;
	}

	dictpoint = fopen(argv[1],"r");
	statpoint = fopen(argv[2],"r");
	if(dictpoint == NULL || statpoint == NULL){
		fprintf(stderr, "invalid input\n");
		return 1;
	}
	readDict(dictpoint);
	/*if dict is invalid return*/	
	if(readval == 1){
		return 1;
	}
	else{
		scanData(statpoint);
	}

	return 0;
}

void readDict(FILE* dict_file){

	int fsize = 0; 
	char* fileBuffer; 
	char c = '0';
	int i = 0;

	fseek(dict_file,0L,SEEK_END);
	fsize = ftell(dict_file); 
	fseek(dict_file,0L,SEEK_SET);
	fileBuffer = (char*)calloc(fsize + 1,sizeof(char));
	if(fsize == 0){
		fprintf(stderr, "empty dictionary\n");
		fclose(dict_file);
		readval = 1;
		return;
	}

	while((c = fgetc(dict_file)) != EOF){
		fileBuffer[i] = c;
		i++;
	}

	fclose(dict_file);
	buildTrie(fileBuffer,fsize);

	free(fileBuffer);
	readval = 0;
	return;
}

void scanData(FILE* data_file){
	char buffer[101];
	char** wordarr;
	int** countarr;
	trieNode* wordtemp = NULL;
	trieNode* counttemp = NULL;
	int wordarrIndex;
	int countarrIndex;
	int i;
	int x;

	/*declare vars for dumping data file into array*/
	int fsize = 0;
	char* fileBuffer;
	int j;
	char c;

	i = 0;
	x = 0;
	wordarrIndex = 0;
	countarrIndex = 0;
	wordtemp = root;
	counttemp = root;
	wordarr = (char**)calloc(gWordCount,sizeof(char*));

	countarr = (int**)calloc(gWordCount,sizeof(int*));
	for(i = 0; i < gWordCount; i++){
		countarr[i] = (int*)calloc(3, sizeof(int));
	}

	/*initialize vars for dumping data file into array*/
	fseek(data_file,0L,SEEK_END);
	fsize = ftell(data_file);
	fseek(data_file,0L,SEEK_SET);
	fileBuffer = (char*)calloc(fsize + 1,sizeof(char));
	j = 0;
	c = '0';

	trieDFS(wordtemp,buffer,wordarr,&wordarrIndex);
	/*prepare for counting instances*/
	while((c = fgetc(data_file)) != EOF){
		fileBuffer[j] = c;
		j++;
	}
	if(c == EOF){
		fileBuffer[j] = '\0';
	}
	fclose(data_file);

	/*start getting counts*/
	counter(fileBuffer,counttemp,countarr,&countarrIndex);

	/*print and done :D*/
	for (x = 0; x < gWordCount; x++) {
		printf("%s %d %d %d\n", wordarr[x], countarr[x][0],countarr[x][1],countarr[x][2]);
	}
}

int trieDFS(trieNode* scout,char* buffer,char** wordarr,int* index){
	int i;

	i = 0;

	if(scout->level > -1){
		buffer[scout->level] = scout->data;
	}

	if(scout->isWord > -1){
		buffer[(scout->level)+1] = '\0';

		wordarr[*index] = (char*)calloc((scout->level+2),sizeof(char));

		memcpy(wordarr[*index],buffer,(scout->level)+1);

		scout->isWord = *index;

		(*index)++;
	}
	for(i = 0; i < 26; i++){
		if(scout == NULL){
			continue;
		}

		else if(scout->next != NULL){
			if(scout->next[i] != NULL){
				trieDFS(scout->next[i],buffer,wordarr,index);
			}
			else{
				continue;
			}
		}
	}


	return 0;
}

void counter(char* fileBuffer,trieNode* scout,int** countarr,int* index){
	/*return on reaching the end of file*/
	if(fileBuffer[*index] == '\0'){
		return;
	}
	/*only happens on characters not in a-z*/
	if((int)fileBuffer[*index] > 122 || (int)fileBuffer[*index] < 97){
		/*for characters from A-Z*/
		if((int)fileBuffer[*index] >= 65 && (int)fileBuffer[*index] <= 90){
			fileBuffer[*index] = (char)((int)fileBuffer[*index] + 32);
		}
		else{
			(*index)++;
			counter(fileBuffer,root,countarr,index);
			return;
		}
	}

	if(scout->next[((int)fileBuffer[*index]) - (int)'a'] == NULL){
		while((int)fileBuffer[(*index)] <= 122 && (int)fileBuffer[(*index)] >= 97){
			(*index)++;
		}
		counter(fileBuffer,root,countarr,index);
		return;
	}
	else{
		scout = scout->next[((int)fileBuffer[*index]) - (int)'a'];
	}


	if((int)fileBuffer[(*index)+1] >= 65 && (int)fileBuffer[(*index)+1] <= 90){
		fileBuffer[(*index)+1] += 32;
	}
	/*superword*/
	if(scout->isWord > -1 && (int)fileBuffer[*index + 1] <= 122 && (int)fileBuffer[*index + 1] >= 97){
		countarr[scout->isWord][2]++;
	}
	/*occurrence*/
	else  {
		if(scout->isWord > -1 && ((int)fileBuffer[*index + 1] > 122 || (int)fileBuffer[*index + 1] < 97)){
		countarr[scout->isWord][0]++;
		}
		/*prefix*/
		if(scout->isWord == -1  && !isalpha(fileBuffer[*index + 1])){
			prefixBot(scout,countarr);
		}
}


	(*index)++;
	counter(fileBuffer,scout,countarr,index);
} 

void prefixBot(trieNode* parent,int** countarr){
	int i;

	i = 0;

	if (parent == NULL) {
		return;
	}
	if(parent->isWord > -1){
		countarr[parent->isWord][1]++;
	}
	for(i = 0; i < 26; i++){
		if(parent->next != NULL){
				prefixBot(parent->next[i],countarr);
		}
	}
}
