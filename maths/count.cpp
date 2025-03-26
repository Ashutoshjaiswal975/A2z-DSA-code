/*
Given a positive integer n, count the number of digits in n that divide n evenly (i.e., without leaving a remainder). Return the total number of such digits.

A digit d of n divides n evenly if the remainder when n is divided by d is 0 (n % d == 0).
Digits of n should be checked individually. If a digit is 0, it should be ignored because division by 0 is undefined.
*/


int solve(int n) {
        int original = n;
        int count = 0;

        while (n > 0) {
            int digit = n % 10;
            // Check if digit is not zero and if it divides the number evenly
            if (digit != 0 && original % digit == 0) {
                count++;
            }
            n /= 10; // Move to the next digit
        }

        return count;
    }

    int evenlyDivides(int n) {
        return solve(n);
    }