#include <vector>
#include <stack>
#include <algorithm> // For std::max
#include <climits>   // For INT_MIN
#include <iostream>  // For std::cout

class Solution {
private:
    std::vector<int> nextSmallerElement(const std::vector<int>& arr, int n) {
        std::stack<int> s;
        std::vector<int> ans(n);

        for (int i = n - 1; i >= 0; --i) {
            int curr = arr[i];
            
            // Pop elements from stack while they are greater than or equal to curr
            while (!s.empty() && arr[s.top()] >= curr) {
                s.pop();
            }

            // If stack is empty, set ans[i] to n; otherwise, set it to the index of the next smaller element
            ans[i] = s.empty() ? n : s.top();
            
            // Push current index onto the stack
            s.push(i);
        }

        return ans;
    }
    
    std::vector<int> prevSmallerElement(const std::vector<int>& arr, int n) {
        std::stack<int> s;
        std::vector<int> ans(n);

        for (int i = 0; i < n; ++i) {
            int curr = arr[i];
            
            // Pop elements from stack while they are greater than or equal to curr
            while (!s.empty() && arr[s.top()] >= curr) {
                s.pop();
            }

            // If stack is empty, set ans[i] to -1; otherwise, set it to the index of the previous smaller element
            ans[i] = s.empty() ? -1 : s.top();
            
            // Push current index onto the stack
            s.push(i);
        }

        return ans; 
    }
    
public:
    int largestRectangleArea(const std::vector<int>& heights) {
        int n = heights.size();
        
        std::vector<int> next = nextSmallerElement(heights, n);
        std::vector<int> prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int height = heights[i];
            
            // Calculate width using next and prev arrays
            int width = next[i] - prev[i] - 1;
            
            // Calculate area for the current height
            int newArea = height * width;
            area = std::max(area, newArea);
        }
        
        return area;
    }
};

// Main function to demonstrate the usage
int main() {
    Solution sol;

    // Example histogram
    std::vector<int> heights = {2, 1, 5, 6, 2, 3};
    
    // Compute the largest rectangle area
    int maxArea = sol.largestRectangleArea(heights);
    
    std::cout << "The largest rectangle area is: " << maxArea << std::endl;

    return 0;
}
