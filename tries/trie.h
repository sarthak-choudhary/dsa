#ifndef _TRIE_H_
#define _TRIE_H_

#include <string>
#include "triesNode.h"

using namespace std;

class Trie {
    TrieNode *root;

    public:

    Trie();
    void insertWord(TrieNode *root, string word);
    void insertWord(string word);
    bool searchWord(TrieNode *root, string word);
    bool searchWord(string word);
    void removeWord(TrieNode *root, string word);
    void removeWord(string word);
};

#endif