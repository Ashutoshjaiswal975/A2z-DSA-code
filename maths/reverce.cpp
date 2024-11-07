/*
Input: x = 123
Output: 321
*/


int reverse(int x) {
         int reversedNumber = 0;
        
        while (x != 0) {
            int digit = x % 10; // Extract the last digit
            x /= 10; // Remove the last digit from x
            
            // Check for overflow/underflow before multiplying by 10
            if (reversedNumber > INT_MAX / 10 || (reversedNumber == INT_MAX / 10 && digit > 7)) {
                return 0; // Overflow
            }
            if (reversedNumber < INT_MIN / 10 || (reversedNumber == INT_MIN / 10 && digit < -8)) {
                return 0; // Underflow
            }
            
            reversedNumber = reversedNumber * 10 + digit;
        }
        
        return reversedNumber;
        
    }