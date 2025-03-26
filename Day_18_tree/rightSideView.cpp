#include <vector>
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfsRightView(TreeNode* root, vector<int> &ans, int level) {
        // Base case
        if (root == NULL) {
            return;
        }
        
        // If this is the first time we've reached a new level
        if (level == ans.size()) {
            ans.push_back(root->val);
        }
        
        // First, explore the right side
        dfsRightView(root->right, ans, level + 1);
        // Then, explore the left side
        dfsRightView(root->left, ans, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfsRightView(root, ans, 0);
        return ans;
    }
};

// Main function to test the rightSideView
int main() {
    // Create a test tree
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    Solution sol;
    vector<int> result = sol.rightSideView(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
