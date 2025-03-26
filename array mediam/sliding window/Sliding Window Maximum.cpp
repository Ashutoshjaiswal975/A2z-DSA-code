/*
Given an array of integers A.  There is a sliding window of size B which 

is moving from the very left of the array to the very right. 

You can only see the w numbers in the window. Each time the sliding window moves 

rightwards by one position. You have to find the maximum for each window. 

The following example will give you more clarity.

The array A is [1 3 -1 -3 5 3 6 7], and B is 3.

Window position	Max
———————————-	————————-
[1  3  -1] -3  5  3  6  7	3
1 [3  -1  -3] 5  3  6  7	3
1  3 [-1  -3  5] 3  6  7	5
1  3  -1 [-3  5  3] 6  7	5
1  3  -1  -3 [5  3  6] 7	6
1  3  -1  -3  5 [3  6  7]	7
Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1].

Note: If B > length of the array, return 1 element with the max of the array.
*/

#include<list>
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
 vector<int> result; // To store the maximum of each window
    list<int> lst;      // To store indices of useful elements in the current window

    for (int i = 0; i < A.size(); i++) {
        // Remove indices that are out of the current window
        if (!lst.empty() && lst.front() == i - B) {
            lst.pop_front();
        }

        // Remove indices of smaller elements as they are not useful
        while (!lst.empty() && A[lst.back()] <= A[i]) {
            lst.pop_back();
        }

        // Add the current element index to the list
        lst.push_back(i);

        // The front of the list contains the maximum for the current window
        if (i >= B - 1) {
            result.push_back(A[lst.front()]);
        }
    }

    return result;
}
