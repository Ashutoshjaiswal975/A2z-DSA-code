#include <vector>
#include <stack>
#include <iostream>

std::vector<int> nextSmallerElement(const std::vector<int> &arr, int n)
{
    std::stack<int> s;
    s.push(-1);  // Use -1 as a default value for the case where no smaller element exists
    std::vector<int> ans(n);

    for (int i = n - 1; i >= 0; --i) {
        int curr = arr[i];
        // Pop elements from the stack while the top element is greater than or equal to curr
        while (!s.empty() && s.top() >= curr) {
            s.pop();
        }
        // If the stack is not empty, the top element is the next smaller element
        ans[i] = s.empty() ? -1 : s.top();
        s.push(curr);  // Push the current element onto the stack
    }

    return ans;
}

// Example usage
int main() {
    std::vector<int> arr = {4, 3, 2, 1, 5, 6};
    int n = arr.size();
    std::vector<int> result = nextSmallerElement(arr, n);

    std::cout << "Next smaller elements: ";
    for (int elem : result) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
