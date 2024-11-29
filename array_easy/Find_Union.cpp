/*
Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.

Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.
Examples:

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: 1 2 3 4 5 6 7
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
*/


class Solution {
    
    //----- brute force
//   public:
//     // a, b : the arrays
//     // Function to return a list containing the union of the two arrays.
//     vector<int> findUnion(vector<int> &a, vector<int> &b) {
//         // Step 1: Combine both arrays into a single array
//         vector<int> unionArray(a.begin(), a.end());
//         unionArray.insert(unionArray.end(), b.begin(), b.end());
        
//         // Step 2: Use a set to remove duplicates
//         set<int> uniqueElements(unionArray.begin(), unionArray.end());
        
//         // Step 3: Convert set back to vector
//         vector<int> result(uniqueElements.begin(), uniqueElements.end());
        
//         // Step 4: Return the sorted union
//         return result;
//     }

//------optimal
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> result;
        int i = 0, j = 0;
        
        // Traverse both arrays
        while (i < a.size() && j < b.size()) {
            // Avoid duplicates in the result
            if (!result.empty() && result.back() == a[i]) {
                i++;
                continue;
            }
            if (!result.empty() && result.back() == b[j]) {
                j++;
                continue;
            }

            // Compare elements from both arrays
            if (a[i] < b[j]) {
                result.push_back(a[i++]);
            } else if (a[i] > b[j]) {
                result.push_back(b[j++]);
            } else {
                // Both are equal, include one and move both pointers
                result.push_back(a[i]);
                i++;
                j++;
            }
        }
        
        // Add remaining elements of `a`
        while (i < a.size()) {
            if (result.empty() || result.back() != a[i]) {
                result.push_back(a[i]);
            }
            i++;
        }
        
        // Add remaining elements of `b`
        while (j < b.size()) {
            if (result.empty() || result.back() != b[j]) {
                result.push_back(b[j]);
            }
            j++;
        }
        
        return result;
    }

};