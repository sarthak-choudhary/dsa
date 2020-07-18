#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data);
    ~BinaryTreeNode();
};

#endif