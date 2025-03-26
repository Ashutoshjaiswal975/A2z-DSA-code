#include <iostream>
#include <algorithm> // For std::max
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // Helper function to calculate if the tree is balanced and its height simultaneously
    pair<bool, int> isbalancedFast(TreeNode* root) {
        // Base case: if the root is NULL, it is balanced and the height is 0
        if (root == NULL) {
            return make_pair(true, 0);  // (isBalanced, height)
        }

        // Recursively check if left and right subtrees are balanced and get their heights
        pair<bool, int> left = isbalancedFast(root->left);
        pair<bool, int> right = isbalancedFast(root->right);

        // Check if the left and right subtrees are balanced
        bool leftBalanced = left.first;
        bool rightBalanced = right.first;

        // Check if the current node's subtrees have a height difference of at most 1
        bool heightDifference = abs(left.second - right.second) <= 1;

        // The current tree is balanced if both subtrees are balanced and the height difference is at most 1
        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;  // Calculate the height of the current node

        if (leftBalanced && rightBalanced && heightDifference) {
            ans.first = true;
        } else {
            ans.first = false;
        }

        return ans;
    }

public:
    // Main function to check if the binary tree is balanced
    bool isBalanced(TreeNode* root) {
        return isbalancedFast(root).first;
    }
};

// Function to create a new node
TreeNode* newNode(int data) {
    TreeNode* node = new TreeNode(data);
    return node;
}

int main() {
    // Create a binary tree
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->left->left->left = newNode(7);

    // Create an instance of the Solution class
    Solution solution;

    // Check if the binary tree is balanced
    bool result = solution.isBalanced(root);
    if (result) {
        cout << "The binary tree is balanced." << endl;
    } else {
        cout << "The binary tree is not balanced." << endl;
    }

    return 0;
}
