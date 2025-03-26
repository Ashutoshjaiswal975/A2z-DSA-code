/*
Given a positive integer n, The task is to find the value of Σi from 1 to n F(i) where function F(i) for the number i is defined as the sum of all divisors of i.

Examples:

Input: n = 4
Output: 15
Explanation:
F(1) = 1
F(2) = 1 + 2 = 3
F(3) = 1 + 3 = 4
F(4) = 1 + 2 + 4 = 7
So, F(1) + F(2) + F(3) + F(4)
    = 1 + 3 + 4 + 7 = 15
*/


class Solution {
  public:
    long long sumOfDivisors(int n) {
    //   long long totalSum = 0;  // This will hold the sum of F(1) + F(2) + ... + F(n)
        
    //     for (int i = 1; i <= n; i++) {
    //         long long currentSum = 0;  // This will hold the sum of divisors of i
            
    //         // Calculate sum of divisors of i
    //         for (int j = 1; j <= i; j++) {
    //             if (i % j == 0) {
    //                 currentSum += j;
    //             }
    //         }
            
    //         // Add the sum of divisors of i to totalSum
    //         totalSum += currentSum;
    //     }
        
    //     return totalSum;  // Return the total sum of all F(i)
    // }
    
    
    long long totalSum = 0;  // This will hold the total sum of F(1) + F(2) + ... + F(n)
        
        // For each divisor from 1 to n, find its contribution to numbers up to n
        for (int d = 1; d <= n; d++) {
            // `d` is a divisor of each multiple of `d` up to `n`
            totalSum += d * (n / d);
        }
        
        return totalSum;  // Return the total sum
    }

};