#ifndef DICTSTAT_H
#define DICTSTAT_H

#include <stdlib.h>
#include <stdio.h>
#include "trie.h"

int readval;

int trieDFS(trieNode* scout,char* buffer,char** wordarr,int* index);
void counter(char* fileBuffer, trieNode* scout,int** countarr, int* index);
void prefixBot(trieNode* parent,int** countarr);

void readDict(FILE* dict_file);
void scanData(FILE* data_file);

#endif
