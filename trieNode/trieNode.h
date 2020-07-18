#ifndef _TRIENODE_H_
#define _TRIENODE_H_

class TrieNode {
    public:
    char data;
    bool isTerminal;
    TrieNode** children;

    TrieNode(char data) {
        this -> data = data;
        children = new TrieNode*[26];
        isTerminal = false;
    }
};

#endif