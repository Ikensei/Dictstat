#ifndef TRIE_H
#define TRIE_H

struct trieNode_ {
	char data;
	int count;
	int isWord;
	int level;
	struct trieNode_* next[26];

};

typedef struct trieNode_ trieNode;

int gWordCount;
trieNode* root;
int add(char toadd,trieNode* parent);
void insert(trieNode* toinsert,trieNode* root);
void deleteOne(trieNode* todelete,trieNode* root);
void deleteTrie(trieNode* root);
trieNode* buildNode(char data,int isWord,int level);
int buildTrie(char* input);
void printTrie(trieNode* root);
int traverseTrie(trieNode* root);

#endif
