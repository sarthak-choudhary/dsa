#include <string>
#include "trie.h"

using namespace std;

Trie::Trie() {
    root = new TrieNode('\0');
}

void Trie::insertWord(TrieNode *root, string word) {
    // Base case 
    if (word.size() == 0) {
        root -> isTerminal = true;
        return;
    }

    // small Calculation

    int index = word[0] - 'a';
    TrieNode *child;
    if (root -> children[index] != NULL) {
        child = root -> children[index];
    } else {
        child = new TrieNode(word[0]);
        root -> children[index] = child;
    }

    // Recursive call
    insertWord(child, word.substr(1));
}

void Trie::insertWord(string word) {
    insertWord(root, word);
}

bool Trie::searchWord(TrieNode *root, string word) {
    if (word.size() == 0) {
        return root -> isTerminal;
    }

    int index = word[0] - 'a';
    if (root -> children[index] == NULL) {
        return false;
    }

    return searchWord(root -> children[index], word.substr(1));
}

bool Trie::searchWord(string word) {
    return searchWord(root, word);
}

void Trie::removeWord(TrieNode *root, string word) {
    // Base case
    if (word.size() == 0) {
        root -> isTerminal = false;
        return;
    }

    // Small calculation
    TrieNode* child;
    int index = word[0] - 'a';
    if (root -> children[index] != NULL) {
        child = root -> children[index];
    } else {
        // word not found
        return;
    }

    removeWord(child, word.substr(1));

    // Remove child Node if it is useless
    if (child -> isTerminal == false) {
        for (int i = 0; i < 26; i++) {
            if (child -> children[i] != NULL) {
                return;
            }
        }

        delete child;
        root -> children[index] = NULL;
    }
}

void Trie::removeWord(string word) {
    removeWord(root, word);
}