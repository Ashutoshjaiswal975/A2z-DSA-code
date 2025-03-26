#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to check if two binary trees are the same
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: if both nodes are NULL, they are the same
        if (p == NULL && q == NULL) {
            return true;
        }

        // If one is NULL and the other is not, they are not the same
        if (p == NULL || q == NULL) {
            return false;
        }

        // Compare the values of the current nodes, and then check left and right subtrees
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        bool value = p->val == q->val;

        // The trees are the same if the current values and both left and right subtrees are the same
        return left && right && value;
    }
};

// Function to create a new node
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Create two sample binary trees
    TreeNode* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);

    TreeNode* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);

    // Create an instance of the Solution class
    Solution solution;

    // Check if the two binary trees are the same
    bool result = solution.isSameTree(root1, root2);
    
    if (result) {
        cout << "The two binary trees are the same." << endl;
    } else {
        cout << "The two binary trees are not the same." << endl;
    }

    return 0;
}
