#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define NUM_CHARS 256

typedef struct trieNode{
    struct TrieNode* children[NUM_CHARS];
    bool endOfWord;
} TrieNode;

Trie* trieCreate() {
    Trie* root = (Trie*) malloc(sizeof(Trie));
    if (root) {
        root->endOfWord = false;
        int i;
        for (i = 0; i < 26; i++) root->children[i] = NULL;
    }
    return root;
}

void trieInsert(Trie* obj, char* word) {
    Trie* temp = obj;
    int i;
    for(i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (!temp->children[index])  // if the node exist
            temp->children[index] = trieCreate(); 
        temp = temp->children[index];
    }
    temp->endOfWord = true;
}

bool trieSearch(Trie* obj, char* word) {
    Trie* temp = obj;
    int i;
    for ( i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (!temp->children[index]) return false;
        temp = temp->children[index];
    }
    return (temp != NULL && temp->endOfWord);
}

bool trieStartsWith(Trie* obj, char* prefix) {
    Trie* temp = obj;
    int i;
    for( i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        if(!temp->children[index]) {
            return false;
        }
        temp = temp->children[index];
    }
    return (temp != NULL);
}

void trieFree(Trie* obj){
    if (obj) {
        int i;
        for (i = 0; i < 26; i++) 
            if (obj->children[i]) trieFree(obj->children[i]); 
    }
    free(obj);
}


int main() {
struct TrieNode* trie = trieCreate();
    trieFree(trie);
    return 0;
}
