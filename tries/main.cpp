#include <iostream>
#include "trie.h"

using namespace std;

int main() {
    // code to use trie
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");

    cout << t.searchWord("and") << endl;

    t.removeWord("and");
    cout << t.searchWord("and") << endl;

}