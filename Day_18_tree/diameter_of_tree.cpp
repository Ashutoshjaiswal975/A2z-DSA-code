#include <iostream>
#include <algorithm> // For max function

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
    // Helper function to calculate height
    int height(TreeNode* root) {
        // Base case: if the node is null, its height is 0
        if (root == NULL) {
            return 0;
        }

        // Recursively calculate the height of the left and right subtrees
        int left = height(root->left);
        int right = height(root->right);

        // Return the height of the current node
        return std::max(left, right) + 1;
    }

public:
    // Function to calculate the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        // Option 1: Diameter in the left subtree
        int opt1 = diameterOfBinaryTree(root->left);

        // Option 2: Diameter in the right subtree
        int opt2 = diameterOfBinaryTree(root->right);

        // Option 3: Diameter through the root
        int opt3 = height(root->left) + height(root->right);

        // The final answer is the maximum of the three options
        return std::max(opt1, std::max(opt2, opt3));
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

    // Create an instance of the Solution class
    Solution solution;

    // Calculate and print the diameter of the binary tree
    int diameter = solution.diameterOfBinaryTree(root);
    std::cout << "The diameter of the binary tree is: " << diameter << std::endl;

    return 0;
}
