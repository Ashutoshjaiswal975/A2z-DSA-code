/*
Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

Note: A subarray is a contiguous part of any given array.

Examples:

Input: arr[] = [100, 200, 300, 400] , k = 2
Output: 700
Explanation: arr3  + arr4 = 700, which is maximum.
*/

int maximumSumSubarray(vector<int>& arr, int k) {
      int start= 0;
      int sum=0, maxSum= INT_MIN;
      for(int i=0; i<arr.size(); i++){
          sum +=arr[i];
          
          if(i-start+1 > k){
              sum -=arr[start];
              start++;
          }
          if(i-start+1==k){
              maxSum=max(maxSum, sum);
          }
      }
      return maxSum;
    }