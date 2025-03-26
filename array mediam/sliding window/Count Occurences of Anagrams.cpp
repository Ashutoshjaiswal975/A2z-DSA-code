/*
Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.

Example 1:

Input: txt = "forxxorfxdofr", pat = "for"
Output: 3
Explanation: for, orf and ofr appears in the txt, hence answer is 3.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
         unordered_map<char, int> patFreq; // Frequency map for the pattern
    unordered_map<char, int> windowFreq; // Frequency map for the current window
    int k = pat.size();       // Length of the pattern
    int n = txt.size();       // Length of the text
    int count = 0;            // To store the count of anagrams

    // Initialize the frequency map for the pattern
    for (char c : pat) {
        patFreq[c]++;
    }

    int i = 0, j = 0; // Sliding window pointers
    while (j < n) {
        // Add the current character to the window frequency
        windowFreq[txt[j]]++;

        // Check if the window size matches the pattern size
        if (j - i + 1 == k) {
            // Compare the current window frequency with the pattern frequency
            if (windowFreq == patFreq) {
                count++;
            }

            // Slide the window by removing the character at index `i`
            windowFreq[txt[i]]--;
            if (windowFreq[txt[i]] == 0) {
                windowFreq.erase(txt[i]); // Clean up zero frequency
            }
            i++;
        }
        j++;
    }

    return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends