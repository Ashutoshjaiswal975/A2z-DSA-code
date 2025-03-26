#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm> // For using sort function
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> nodes;  // Map to store (horizontal distance -> level -> node values)
        queue<pair<TreeNode*, pair<int, int>>> q;  // Queue for BFS (node, (horizontal distance, level))
        vector<vector<int>> ans;  // Final answer
        
        if (root == NULL) {
            return ans;  // Return empty vector if tree is empty
        }

        q.push(make_pair(root, make_pair(0, 0)));  // Initialize with the root node at hd=0, lvl=0
        
        // BFS traversal to fill the `nodes` map
        while (!q.empty()) {
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();
            
            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;  // Horizontal distance
            int lvl = temp.second.second;  // Level
            
            // Store the current node value at the correct position in the map
            nodes[hd][lvl].push_back(frontNode->val);
            
            // Add left child to the queue with updated hd and level
            if (frontNode->left) {
                q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
            }
            
            // Add right child to the queue with updated hd and level
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
            }
        }
        
        // Traverse the map and construct the final answer
        for (map<int, map<int, vector<int>>>::iterator i = nodes.begin(); i != nodes.end(); ++i) {
            vector<int> column;  // Temporary vector to store each vertical column
            for (map<int, vector<int>>::iterator j = i->second.begin(); j != i->second.end(); ++j) {
                // Sorting is required to ensure that nodes at the same level and horizontal distance are in the correct order.
                sort(j->second.begin(), j->second.end());
                for (vector<int>::iterator k = j->second.begin(); k != j->second.end(); ++k) {
                    column.push_back(*k);  // Collect all nodes for this vertical line
                }
            }
            ans.push_back(column);  // Add the current vertical line to the final answer
        }
        
        return ans;
    }
};

// Helper function to create a test binary tree
TreeNode* createTestTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    Solution solution;
    TreeNode* root = createTestTree();

    // Get the vertical order traversal
    vector<vector<int>> result = solution.verticalTraversal(root);

    // Print the result
    for (size_t i = 0; i < result.size(); ++i) {
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
