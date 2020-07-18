#include <iostream>
#include <queue>
#include "treeUse.cpp" 

using namespace std;
template <typename T>
TreeNode<T>* takeInputLevelWise(T sample) {
    T rootData {};
    cout << "enter the data" << endl;
    cin >> rootData;

    TreeNode<T>* root = new TreeNode<T>(rootData);
    queue<TreeNode<T>*> q;

    q.push(root);

    while (q.size() != 0) {
        TreeNode<T> *front = q.front();
        q.pop();
        int numChild {};
        cout << "Enter the number of children of " << front -> data << endl;
        cin >> numChild;

        for (int i = 0; i < numChild; i++) {
            cout << "Enter the data for " << i + 1 << "th child of" << front -> data <<endl;
            T childData {};
            cin >> childData;
            TreeNode<T> *child = new TreeNode<T>(childData);
            front -> children.push_back(child);
            q.push(child);
        } 
    }

    return root;
}

template <typename T>
TreeNode<T>* takeInput(T sample) {
    T rootData {};
    cout << "enter the data" << endl;
    cin >> rootData;

    TreeNode<T>* root = new TreeNode<T>(rootData);

    cout << "Number of children of " << rootData << endl;
    int n {};
    cin >> n;

    for (int i = 0; i < n; i++) {
        TreeNode<T>* child = takeInput(sample);
        root -> children.push_back(child);
    }

    return root;
}

template <typename T>
void printTree(TreeNode<T>* root) {
    if (root == NULL) {
        return;
    }

    cout << root -> data << ": " ;

    for (int i = 0; i < root -> children.size(); i++) {
        cout << root -> children[i] -> data << ", " ;
    }

    cout << endl;

    for (int i = 0; i < root -> children.size(); i++) {
        printTree(root -> children[i]);
    }
}

template <typename T>
void printTreeLevelWise(TreeNode<T>* root) {
    queue<TreeNode<T>*> q;
    q.push(root);

    while(q.size() != 0) {
        TreeNode<T>* front = q.front();
        q.pop();

        cout << front -> data << ": ";
        for (int i = 0; i < front -> children.size(); i++) {
            TreeNode<T>* child = front -> children[i];
            cout << child -> data << ", ";
            q.push(child);
        }

        cout << endl;
    } 
}

void deleteTree(TreeNode<int>* root) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < root -> children.size(); i++) {
        deleteTree(root -> children[i]);
    }

    delete root;
}

void printLevelk(TreeNode<int>* root, int k) {
    if (root == NULL || k < 1) {
        return;
    }

    if (k == 1) {
        cout << root -> data << " ";
    }

    for (int i = 0; i < root -> children.size(); i++) {
        printLevelk(root -> children[i], k - 1);
    }
}

void printLevelWise(TreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while (q.size() != 0) {
        TreeNode<int>* front = q.front();
        q.pop();
        
        cout << front -> data << ":";
        if (front -> children.size() > 0) {
            for (int i = 0; i < front -> children.size() - 1; i++) {
                TreeNode<int>* child = front -> children[i];
                cout << child -> data << ",";
                q.push(child);
            }
        
            TreeNode<int>* lastChild = front -> children[front -> children.size() - 1];
            cout << lastChild -> data << endl;
            q.push(lastChild);
        } else {
            cout << endl;
        }
    }
}

TreeNode<int>* largestNode(TreeNode<int> *root) {
    TreeNode<int>* currentLargest = root;
    
    for (int i = 0; i < root -> children.size(); i++) {
        TreeNode<int>* smallOutput = largestNode(root -> children[i]);
        if (smallOutput -> data > currentLargest -> data) {
            currentLargest = smallOutput;
        }
    }
    
    return currentLargest;
}

TreeNode <int>* secondLargest(TreeNode<int> *root) {
    if (root == NULL) {
        return NULL;
    }
    
	TreeNode<int>* largest = root;
    TreeNode<int>* second = NULL;
    
    for (int i = 0; i < root -> children.size(); i++) {
        TreeNode<int>* smallOutputLargest = largestNode(root -> children[i]);
        TreeNode<int>* smallOutputSecond = secondLargest(root -> children[i]);
        if (smallOutputLargest -> data > largest -> data) {
            second = largest;
            largest = smallOutputLargest;
            if (smallOutputSecond -> data > second -> data) {
                second = smallOutputSecond;
            }
        } else if (second != NULL && smallOutputLargest -> data > second -> data) {
            second = smallOutputLargest;
        } else if (second == NULL) {
            second = smallOutputLargest;
        }
    }
    
    return second;
    
}
int main() {
    TreeNode<int>* root = takeInputLevelWise(0);
    TreeNode<int>* temp = secondLargest(root);
    cout << temp -> data << endl;
    delete root;
}