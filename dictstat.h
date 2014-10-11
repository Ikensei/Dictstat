/*pelvic sorcery*/

#ifndef DICTSTAT_H
#define DICTSTAT_H

int readval;
void readDict(FILE* dict_file);
void scanData(FILE* data_file);
int trieDFS(trieNode* scout,char* buffer, char** wordarr,int* index);
int counter(FILE* data_file, trieNode* scout,int** countarr, int* index);

#endif
