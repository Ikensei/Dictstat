#include <stdio.h>
#include <stlib.h>
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
	int i;

	i = 0;
	wordarr = malloc(gWordCount*sizeof(char*));
	countarr = malloc(3*sizeof(int*));

	for(i = 0;i < gWordCount;i++){

	}







}
