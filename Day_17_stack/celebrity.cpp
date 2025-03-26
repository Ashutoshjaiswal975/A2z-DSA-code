#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    bool knows(vector<vector<int>>& M, int a, int b) {
        // Return true if person a knows person b, false otherwise
        return M[a][b] == 1;
    }
    
public:
    // Function to find if there is a celebrity in the party or not
    int celebrity(vector<vector<int>>& M, int n) {
        stack<int> s;

        // Step 1: Push all individuals onto the stack
        for (int i = 0; i < n; i++) {
            s.push(i);
        }

        // Step 2: Process the stack to find the potential celebrity
        while (s.size() > 1) {
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            // If a knows b, then a cannot be a celebrity. Push b back to stack.
            if (knows(M, a, b)) {
                s.push(b);
            } else {
                // If a does not know b, then b cannot be a celebrity. Push a back to stack.
                s.push(a);
            }
        }
        
        // The remaining person in the stack is a potential celebrity
        int ans = s.top();
        
        // Step 3: Verify the potential celebrity
        int zeroCount = 0;
        
        // Verify that the potential celebrity does not know anyone
        for (int i = 0; i < n; i++) {
            if (M[ans][i] == 0) {
                zeroCount++;
            }
        }
        
        // The potential celebrity should not know anyone (including themselves)
        if (zeroCount != n) {
            return -1;
        }
        
        int oneCount = 0;
        
        // Verify that everyone knows the potential celebrity
        for (int i = 0; i < n; i++) {
            if (M[i][ans] == 1) {
                oneCount++;
            }
        }
        
        // Everyone should know the celebrity except the celebrity themselves
        if (oneCount != n - 1) {
            return -1;
        }
        
        return ans;
    }
};

int main() {
    // Example usage
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    int n = M.size();
    
    Solution sol;
    int celeb = sol.celebrity(M, n);
    
    if (celeb == -1) {
        cout << "No celebrity found." << endl;
    } else {
        cout << "The celebrity is person " << celeb << "." << endl;
    }
    
    return 0;
}
