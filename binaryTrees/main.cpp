#include <iostream>
#include <climits>
#include <queue>
#include "bst.cpp"
#include <vector>

using namespace std;

void createVector(vector<int> &nodes, BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    
    nodes.push_back(root -> data);
    createVector(nodes, root -> left);
    createVector(nodes, root -> right);
}

vector<int> mergeSort(vector<int>& v) {
    if (v.size() == 1) {
        return v;
    }

    vector<int> sortedLeft;
    vector<int> sortedRight;

    for (int i = 0; i < (v.size() + 1)/2; i++) {
        sortedLeft.push_back(v[i]);
    }

    for (int i = 0; i < v.size()/2; i++) {
        sortedRight.push_back(v[i + (v.size() + 1)/2]);
    }

    sortedLeft = mergeSort(sortedLeft);
    sortedRight = mergeSort(sortedRight);

    int leftPointer {};
    int rightPointer {};
    int p {};
    while (leftPointer < sortedLeft.size() && rightPointer < sortedRight.size()) {
        if (sortedRight[rightPointer] > sortedLeft[leftPointer]) {
            v[p] = sortedLeft[leftPointer];
            leftPointer++;
            p++;
        } else {
            v[p] = sortedRight[rightPointer];
            rightPointer++;
            p++;
        }
    }

    while (rightPointer < sortedRight.size()) {
        v[p] = sortedRight[rightPointer];
        rightPointer++;
        p++;
    }

    while (leftPointer < sortedLeft.size()) {
        v[p] = sortedLeft[leftPointer];
        leftPointer++;
        p++;
    }

    return v;
}

template <typename T>
void printBinaryTree(BinaryTreeNode<T>* root) {
    if (root == NULL) {
        return;
    }

    cout << root -> data << ":";
    if (root -> left != NULL) {
        cout << "L " << root -> left -> data << ",";
    }

    if (root -> right != NULL) {
        cout << "R " << root -> right -> data ;
    }

    cout << endl;

    printBinaryTree(root -> left);
    printBinaryTree(root -> right);
}

template <typename T>
BinaryTreeNode<T>* takeInputLevelwise (T sample) {
    T rootData {};
    cout << "Enter the Data" << endl;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }

    BinaryTreeNode<T>* root = new BinaryTreeNode<T>(rootData);
    queue<BinaryTreeNode<T>*> q;
    q.push(root);

    while (q.size() != 0) {
        BinaryTreeNode<T>* front = q.front();
        q.pop();

        cout << "Enter the data for left of " << front -> data << endl;
        cin >> rootData;

        if (rootData != -1) {
            BinaryTreeNode<T>* leftChild = new BinaryTreeNode<T>(rootData);
            front -> left = leftChild;
            q.push(leftChild);
        }

        cout << "Enter the data for the right of " << front -> data << endl;
        cin >> rootData;

        if (rootData != -1) {
            BinaryTreeNode<T>* rightChild = new BinaryTreeNode<T>(rootData);
            front -> right = rightChild;
            q.push(rightChild);
        }
    }

    return root;
}

bool isBST(BinaryTreeNode<int>* root, int max = INT_MAX, int min = INT_MIN) {
    if (root == NULL) {
        return true;
    }

    if (root -> data > max || root -> data < min) {
        return false;
    }

    bool isRightOk = isBST(root -> right, max, root -> data);
    bool isLeftOk = isBST(root -> left, root -> data - 1, min);

    return isLeftOk && isRightOk;
}

template <typename T>
BinaryTreeNode<T>* takeInput(T sample) {
    T rootData {};
    cout << "Enter the Data" << endl;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }

    BinaryTreeNode<T>* root = new BinaryTreeNode<T>(rootData);
    BinaryTreeNode<T>* leftChild = takeInput(sample);
    BinaryTreeNode<T>* rightChild = takeInput(sample);

    root -> left = leftChild;
    root -> right = rightChild;

    return root;
}

pair<vector<int>&, bool> searchAndPath(BinaryTreeNode<int>* root, vector<int>& path, int data) {
    if (root == NULL) {
        pair<vector<int>&, bool> pairAns(path, false);
        return pairAns;
    }
    
    if (root -> data == data) {
        path.push_back(data);
        pair<vector<int>&, bool> pairAns(path, true);
        return pairAns;
    }
    
    pair<vector<int>&, bool> leftChild = searchAndPath(root -> left, path, data);
    
    if(leftChild.second == true) {
        leftChild.first.push_back(root -> data);
        return leftChild;
    }
    
    pair<vector<int>&, bool> rightChild = searchAndPath(root -> right, path, data);
    
    if(rightChild.second == true) {
        rightChild.first.push_back(root -> data);
        return rightChild;
    }
    
    pair<vector<int>&, bool> pairAns(path, false);    
    return pairAns;
}

vector<BinaryTreeNode<int>*> nodes;

void largerNodes(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }

    largerNodes(root -> left);
    nodes.push_back(root);
    largerNodes(root -> right);
}


int main() {
    BinaryTreeNode<int>* root = takeInputLevelwise(0);
    printBinaryTree(root);

    cout << endl;

    largerNodes(root);
    int sum {};

    for (int i = nodes.size() - 1; i <= 0; i--) {
        int nodeData = nodes[i] -> data;
        nodes[i] -> data = nodes[i] -> data + sum;
        sum = sum + nodeData;
    }

    printBinaryTree(root);
}