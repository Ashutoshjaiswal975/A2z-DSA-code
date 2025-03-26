#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result; // To store the final zigzag order
        if (root == NULL) {
            return result; // Return empty if the tree is empty
        }

        queue<TreeNode*> q;
        q.push(root); // Initialize the queue with the root node

        bool leftToRight = true; // Flag to control the zigzag direction
        while (!q.empty()) {
            int size = q.size(); // Number of nodes at the current level
            vector<int> ans(size); // To store the current level nodes in the correct order

            for (int i = 0; i < size; i++) {
                TreeNode* frontNode = q.front();
                q.pop();

                // Determine where to place the current node's value in the ans vector
                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->val;

                // Add the child nodes to the queue for the next level
                if (frontNode->left) {
                    q.push(frontNode->left);
                }
                if (frontNode->right) {
                    q.push(frontNode->right);
                }
            }

            // After processing all nodes at the current level, add the result to the final result
            result.push_back(ans);
            
            // Toggle the direction for the next level
            leftToRight = !leftToRight;
        }

        return result; // Return the zigzag level order result
    }
};

// Helper function to build a sample tree for testing
TreeNode* createTestTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    Solution solution;
    TreeNode* root = createTestTree();

    // Get the zigzag level order traversal
    vector<vector<int>> result = solution.zigzagLevelOrder(root);

    // Print the result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
