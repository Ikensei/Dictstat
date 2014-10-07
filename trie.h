#ifndef TRIE_H
#define TRIE_H

struct trieNode_ {
	char data;
	int count;
	unsigned char isWord;
	int level;
	struct trieNode_* next[26];

};

typedef struct trieNode_ trieNode;

void add(trieNode* toadd,trieNode* root);
void insert(trieNode* toinsert,trieNode* root);
void deleteOne(trieNode* todelete,trieNode* root);
void deleteTree(trieNode* root);
trieNode* buildNode(char data,unsigned char isWord,int level);
trieNode* buildTree(char* input);
void printTrie(trieNode* root);

#endif
