/*
Given a string s, you need to print the size of the longest possible substring with exactly k unique characters. If no possible substring exists, print -1.

Examples:

Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: "cbebebe" is the longest substring with 3 distinct characters.
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.
*/

int longestKSubstr(string &s, int k) {
          unordered_map<char, int> charCount; // To store character frequencies
    int maxLength = -1;                // To store the length of the longest substring
    int i = 0;                      // Left pointer of the sliding window

    for (int j = 0; j < s.size(); ++j) {
        charCount[s[j]]++;         // Add the current character to the window

        // If the window contains more than k distinct characters, shrink it
        while (charCount.size() > k) {
            charCount[s[i]]--;      // Reduce the frequency of the left character
            if (charCount[s[i]] == 0) {
                charCount.erase(s[i]); // Remove the character if its frequency is 0
            }
            ++i;                    // Move the left pointer forward
        }

        // If the window contains exactly k distinct characters, update maxLength
        if (charCount.size() == k) {
            maxLength = max(maxLength, j - i + 1);
        }
    }

    return maxLength;
    }