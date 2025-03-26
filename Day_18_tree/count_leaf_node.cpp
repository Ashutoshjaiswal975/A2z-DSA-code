#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to perform inorder traversal and count leaf nodes
void inorder(TreeNode* root, int &count) {
    // Base case: if the node is NULL, return
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    inorder(root->left, count);
    
    // Check if the current node is a leaf node
    if (root->left == NULL && root->right == NULL) {
        count++;
    }
    
    // Traverse the right subtree
    inorder(root->right, count);
}

class Solution {
public:
    int countNodes(TreeNode* root) {
        int cnt = 0;
        inorder(root, cnt);
        return cnt;
    }
};

// Example usage
int main() {
    // Creating a simple tree: 
    //       1
    //      / \
    //     2   3
    //    /
    //   4
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    
    Solution sol;
    int leafCount = sol.countNodes(root);
    cout << "Number of leaf nodes: " << leafCount << endl; // Output: 2 (nodes 3 and 4)

    // Clean up
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
