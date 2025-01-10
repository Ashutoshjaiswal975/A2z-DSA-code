/*
Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
*/

int lengthOfLongestSubstring(string s) {
         unordered_set<char> charSet;  // To store characters in the current window
    int maxLength = 0;           // To store the length of the longest substring
    int left = 0;                // Left pointer of the sliding window

    for (int right = 0; right < s.size(); ++right) {
        // If the character already exists in the window, shrink the window
        while (charSet.find(s[right]) != charSet.end()) {
            charSet.erase(s[left]);  // Remove the left character
            ++left;                  // Move the left pointer forward
        }
        
        charSet.insert(s[right]);    // Add the current character to the window
        maxLength = max(maxLength, right - left + 1);  // Update the max length
    }

    return maxLength;
    }