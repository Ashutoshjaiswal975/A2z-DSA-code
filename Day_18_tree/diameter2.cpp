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
public:
    // Helper function to calculate diameter and height simultaneously
    pair<int, int> diameterFast(TreeNode* root) {
        // Base case: if the root is NULL, diameter and height are both 0
        if (root == NULL) {
            return make_pair(0, 0);  // (diameter, height)
        }

        // Recursively calculate the diameter and height of the left and right subtrees
        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);

        // Option 1: Diameter in the left subtree
        int opt1 = left.first;

        // Option 2: Diameter in the right subtree
        int opt2 = right.first;

        // Option 3: Diameter passing through the current root
        int opt3 = left.second + right.second + 1;

        // The diameter of the current tree is the maximum of the three options
        int diameter = max(opt1, max(opt2, opt3));

        // The height of the current node is the maximum height of its subtrees plus 1
        int height = max(left.second, right.second) + 1;

        // Return a pair of diameter and height
        return make_pair(diameter, height);
    }

    // Function to return the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        // The first element of the pair is the diameter
        return diameterFast(root).first - 1; // Subtract 1 to get the actual number of edges
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
    cout << "The diameter of the binary tree is: " << diameter << endl;

    return 0;
}
