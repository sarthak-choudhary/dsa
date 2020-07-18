#include <iostream>
#include "binaryTree.h"

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(T data)
    :data {data}, left {NULL}, right {NULL} {

    }

template <typename T>
BinaryTreeNode<T>::~BinaryTreeNode() {
    delete left;
    delete right;
}