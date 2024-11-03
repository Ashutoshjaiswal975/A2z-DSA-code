/* Problem statement
Aryan and his friends are very fond of patterns. For a given integer ‘N’, they want to make the Increasing Letter Triangle.

Example:
Input: ‘N’ = 3

Output: 

A
A B
A B C
*/

void nLetterTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        // Print letters from 'A' up to the ith letter
        for (int j = 0; j < i; j++) {
            cout << char('A' + j) << " ";
        }
        cout << endl; // Move to the next line after each row
    }
}