#include <stdio.h>
#include <stlib.h>
#include <string.h>
#include "dictstat.h"
#include "trie.h"

int main(int argc,char** argv){
	FILE* dictpoint = NULL;
	FILE* statpoint = NULL;
	root = NULL;

	if(argc < 3){
		fprintf("stderr", "invalid input\n");
		return 1;
	}

	dictpoint = fopen(argv[1],"r");
	statpoint = fopen(argv[2],"r");
	if(dictpoint == NULL || statpoint == NULL){
		fprintf("stderr", "invalid input\n");
		return 1;
	}

	readDict(dictpoint)
	if(readval == 1){
		return;
	}
	else{
	scanData(statpoint);
	}

	return 0;
}

void readDict(FILE* dict_file){

	int fsize = fseek(dict_file,0,SEEK_END) - fseek(dict_file,0,SEEK_SET);
	char* fileBuffer = (char*)calloc(fsize + 1,sizeof(char));

	char c = '0';
	int i = 0;

	if(fsize == 0){
		fprintf("stderr", "empty dictionary\n");
		fclose(dict_file);
		readval = 1;
		return;
	}

	while((c = fgetc(dict_file)) != EOF){
		fileBuffer[i] = c;
		i++;
	}
	
	fclose(dict_file);
	root =  buildTrie(fileBuffer);

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
	
	i = 0;
	wordarrIndex = 0;
	wordtemp = root;
	counttemp = root;
	wordarr = malloc(gWordCount*sizeof(char*));
	countarr = calloc(gWordCount,sizeof(int*));

	for(i = 0; i < gWordCount; i++){
		countarr[i] = malloc(3*sizeof(int));
	}

	trieDFS(wordtemp,buffer,wordarr,&wordarrIndex);

	/*prepare for counting instances*/
	counter(data_file,counttemp,countarr,&countarrIndex);
}

int trieDFS(trieNode* scout,char* buffer,char** wordarr,int* index){
	int i;

	int i = 0;

	if(scout->level > -1){
		buffer[scout->level] = scout->data;
	}

	if(scout->isWord > -1){
		buffer[(scout->level)+1] = '\0';

		wordarr[*index] = (char*)malloc((scout->level+1)*sizeof(char));

		memcpy(wordarr[*index],buffer,(scout->level)+1);

		scout->isWord = *index;

		(*index)++;

		memset(buffer + (scout->level + 1),0,1);
	}

	for(i = 0; i < 26; i++){
		if(scout->next != NULL){
			trieDFS(scout->next[i],buffer,wordarr,index);
		}
	}

	return 0;		
}

int counter(FILE* data_file,trieNode* scout,int** countarr,int* index){
	int fsize = fseek(data_file,0,SEEK_END) - fseek(data_file,0,SEEK_SET);
	char* fileBuffer = (char*)calloc(fsize + 1,sizeof(char));

	char c = '0';
	int j = 0;

	if(fsize == 0){

	}

	while((c = fgetc(data_file)) != EOF){
		fileBuffer[i] = c;
		i++;
	}
	
	fclose(data_file);

} 
