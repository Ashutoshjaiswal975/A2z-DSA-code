/*

A number n is called a factorial number if it is the factorial of a positive integer. For example, the first few factorial numbers are 1, 2, 6, 24, 120,
Given a number n, the task is to return the list/vector of the factorial numbers smaller than or equal to n.

Examples:

Input: n = 3
Output: 1 2
Explanation: The first factorial number is 1 which is less than equal to n. The second number is 2 which is less than equal to n,but the third factorial number is 6 which is greater than n. So we print only 1 and 2.
*/


 void generateFactorials(long long n, long long current, long long fact, std::vector<long long>& result) {
        // Base case: stop recursion if the current factorial exceeds n
        if (fact > n) {
            return;
        }

        // Add the current factorial to the result vector
        result.push_back(fact);

        // Recursive call to compute the next factorial
        generateFactorials(n, current + 1, fact * (current + 1), result);
    }

    std::vector<long long> factorialNumbers(long long n) {
        std::vector<long long> result;  // Corrected the typo here
        generateFactorials(n, 1, 1, result);  // Start from 1! = 1
        return result;
    }
    
    //   vector<long long> result;
    //     long long fact = 1;
    //     long long i = 1;
        
    //     // Generate all factorials less than or equal to n
    //     while (fact <= n) {
    //         result.push_back(fact);
    //         i++;
    //         fact *= i;  // Calculate the next factorial (i!)
    //     }
        
    //     return result;