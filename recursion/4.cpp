/*
Input: n = 5
Output: 225
Explanation: 13 + 23 + 33 + 43 + 53 = 225
*/


long long sumOfSeries(long long n) {
      if(n==0){
          return 0;
      }
      long long c= sumOfSeries(n-1)+(n*n*n);
      return c;
    }