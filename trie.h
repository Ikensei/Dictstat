#ifndef TRIE_H
#define TRIE_H

struct trieNode_ {
	char data;
	int count;
	int isWord;
	int level;
	struct trieNode_* next[26];
	struct trieNode_* parent;

};

typedef struct trieNode_ trieNode;

int gWordCount;
trieNode* root;
int add(char toadd,trieNode* parent);
void insert(trieNode* toinsert,trieNode* parent);
void deleteOne(trieNode* todelete);
void deleteTrie(trieNode* parent);
trieNode* buildNode(char data,int isWord,int level);
int buildTrie(char* input, size_t size);
void printTrie(trieNode* parent);
int traverseTrie(trieNode* parent);

#endif
