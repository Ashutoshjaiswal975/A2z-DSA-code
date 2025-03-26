#include <iostream>
#include <vector>
#include <algorithm>

// Recursive function to solve the knapsack problem
int solve(const std::vector<int>& weight, const std::vector<int>& value, int index, int capacity) {
    // Base case: if only one item is available
    if (index == 0) {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    // Option 1: Include the current item, if its weight is less than or equal to capacity
    int include = 0;
    if (weight[index] <= capacity) {
        include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);
    }

    // Option 2: Exclude the current item
    int exclude = solve(weight, value, index - 1, capacity);

    // Return the maximum value of including or excluding the current item
    return std::max(include, exclude);
}

// Function to calculate the maximum value for the knapsack
int knapsack(const std::vector<int>& weight, const std::vector<int>& value, int n, int capacity) {
    return solve(weight, value, n - 1, capacity);
}

int main() {
    int n, capacity;
    std::cout << "Enter number of items and knapsack capacity: ";
    std::cin >> n >> capacity;

    std::vector<int> weight(n), value(n);

    std::cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        std::cin >> weight[i];
    }

    std::cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        std::cin >> value[i];
    }

    std::cout << "Maximum value in the knapsack: " << knapsack(weight, value, n, capacity) << std::endl;

    return 0;
}

/*#include <iostream>
#include <vector>
#include <algorithm>

// Recursive function to solve the knapsack problem with memoization
int solve(const std::vector<int>& weight, const std::vector<int>& value, int index, int capacity, std::vector<std::vector<int>>& dp) {
    // Base case: if only one item is available
    if (index == 0) {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    // If the result for this subproblem is already calculated, return it
    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    // Option 1: Include the current item, if its weight is less than or equal to capacity
    int include = 0;
    if (weight[index] <= capacity) {
        include = value[index] + solve(weight, value, index - 1, capacity - weight[index], dp);
    }

    // Option 2: Exclude the current item
    int exclude = solve(weight, value, index - 1, capacity, dp);

    // Memoize and return the maximum value of including or excluding the current item
    dp[index][capacity] = std::max(include, exclude);
    return dp[index][capacity];
}

// Function to calculate the maximum value for the knapsack
int knapsack(const std::vector<int>& weight, const std::vector<int>& value, int n, int capacity) {
    // Create a memoization table and initialize it with -1
    std::vector<std::vector<int>> dp(n, std::vector<int>(capacity + 1, -1));
    return solve(weight, value, n - 1, capacity, dp);
}

int main() {
    int n, capacity;
    std::cout << "Enter number of items and knapsack capacity: ";
    std::cin >> n >> capacity;

    std::vector<int> weight(n), value(n);

    std::cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        std::cin >> weight[i];
    }

    std::cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        std::cin >> value[i];
    }

    std::cout << "Maximum value in the knapsack: " << knapsack(weight, value, n, capacity) << std::endl;

    return 0;
}

*/
