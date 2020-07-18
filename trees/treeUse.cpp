#include "tree.h"

template <typename T>

TreeNode<T>::TreeNode(T data)
    :data {data} {

    }

template <typename T>
TreeNode<T>::~TreeNode() {
    for (int i = 0; i < children.size(); i++) {
        delete children[i];
    }
}