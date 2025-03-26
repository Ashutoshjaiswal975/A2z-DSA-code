#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    // Traverse the left boundary (excluding leaf nodes)
    void traverseLeft(Node* root, vector<int>& ans) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;
        
        ans.push_back(root->data);  // Add the current node to the boundary
        
        if (root->left) {
            traverseLeft(root->left, ans);  // Continue on the left subtree
        } else {
            traverseLeft(root->right, ans);  // If no left child, continue on the right subtree
        }
    }
    
    // Traverse all the leaf nodes
    void traverseLeaf(Node* root, vector<int>& ans) {
        if (root == NULL)
            return;
        
        // If it's a leaf node, add it to the boundary
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
        
        traverseLeaf(root->left, ans);  // Continue on the left subtree
        traverseLeaf(root->right, ans);  // Continue on the right subtree
    }
    
    // Traverse the right boundary (excluding leaf nodes)
    void traverseRight(Node* root, vector<int>& ans) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;
        
        if (root->right) {
            traverseRight(root->right, ans);  // Continue on the right subtree
        } else {
            traverseRight(root->left, ans);  // If no right child, continue on the left subtree
        }
        
        ans.push_back(root->data);  // Add the current node to the boundary after recursion
    }
    
    // Function to return the boundary traversal of a binary tree
    vector<int> boundary(Node* root) {
        vector<int> ans;
        
        if (root == NULL)  // Base case: if the tree is empty
            return ans;
        
        ans.push_back(root->data);  // Add root data to the boundary
        
        // 1. Traverse the left boundary (excluding leaf nodes)
        traverseLeft(root->left, ans);
        
        // 2. Traverse the leaf nodes in left and right subtrees
        // Left subtree leaves
        traverseLeaf(root->left, ans);
        // Right subtree leaves
        traverseLeaf(root->right, ans);
        
        // 3. Traverse the right boundary (excluding leaf nodes)
        traverseRight(root->right, ans);
        
        return ans;
    }
};

// Helper function to create a test tree
Node* createTestTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    return root;
}

int main() {
    Solution solution;
    Node* root = createTestTree();
    
    // Get the boundary traversal
    vector<int> result = solution.boundary(root);
    
    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    
    return 0;
}
