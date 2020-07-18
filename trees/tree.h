#ifndef _TREE_H_
#define _TREE_H_

#include <vector>
using namespace std;

template <typename T>

class TreeNode {
    public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data);
    ~TreeNode();
};

#endif