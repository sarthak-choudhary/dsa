#include "binaryTree.cpp"

class BST {
    public:
    BinaryTreeNode<int>* root;
    bool hasDataHelper(BinaryTreeNode<int>* node, int data) {
        if (node == NULL) {
            return false;
        }

        if (node -> data == data) {
            return true;
        } else if (node -> data > data) {
            return hasDataHelper(node -> left, data);
        } else {
            return hasDataHelper(node -> right, data);
        }

        
    }

    BinaryTreeNode<int>* smallestNode(BinaryTreeNode<int>* rootNode) {
        BinaryTreeNode<int>* temp  = rootNode;

        while (temp -> left != NULL) {
            temp = temp -> left;
        }

        return temp;
    }

    BinaryTreeNode<int>* insertHelper(BinaryTreeNode<int>* rootNode, int data) {
        if (rootNode == NULL) {
            BinaryTreeNode<int>* node = new BinaryTreeNode<int>(data);
            return node;
        }

        if (rootNode -> data > data) {
            BinaryTreeNode<int>* leftChild = insertHelper(rootNode -> left, data);
            rootNode -> left = leftChild;
            return rootNode;
        } else {
            BinaryTreeNode<int>* rightChild = insertHelper(rootNode -> right, data);
            rootNode -> right = rightChild;
            return rootNode;
        }
    }

    BinaryTreeNode<int>* deleteHelper(BinaryTreeNode<int>* rootNode, int data) {
        if (rootNode == NULL) {
            return NULL;
        }

        if (rootNode -> data > data) {
            rootNode -> left = deleteHelper(rootNode -> left, data);
            return rootNode;
        } else if (rootNode -> data < data) {
            rootNode -> right = deleteHelper(rootNode -> right, data);
            return rootNode;
        } else {
            if (rootNode -> left == NULL && rootNode -> right == NULL) {
                delete rootNode;
                return NULL;
            } else if (rootNode -> left == NULL) {
                BinaryTreeNode<int>* output = rootNode -> right;
                delete rootNode;
                return output;
            } else if (rootNode -> right == NULL) {
                BinaryTreeNode<int>* output = rootNode -> left;
                delete rootNode;
                return output;
            } else {
                BinaryTreeNode<int>* minRight = smallestNode(root -> right);
                rootNode -> data = minRight -> data;
                rootNode -> right = deleteHelper(rootNode -> right, minRight -> data);
                return rootNode;
            }
        }
    }

    BST() {
        root = NULL;
    }

    ~BST() {
        delete root;
    }

    bool hasData(int data) {
        return hasDataHelper(root, data);
    }

    void insert(int data) {
        root = insertHelper(root, data);
        return;
    }

    void deleteNode(int data) {
        root = deleteHelper(root, data);
        return;
    }
};