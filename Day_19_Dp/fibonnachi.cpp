#include <iostream>
#include <vector>
using namespace std;


/*
    int fib(int n) {
        if(n<=1){
            return n;
        }
    vector<int> dp(n+1);
    for(int i=0; i<=n; i++){
        dp[i]=-1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n]=fib(n-1)+fib(n-2);
    return dp[n];
    */
/*
int fib(int n) {
    if (n <= 1) {
        return n;
    }

    // Create a dp array to store Fibonacci numbers
    vector<int> dp(n + 1);

    // Initialize base cases
    dp[0] = 0;
    dp[1] = 1;

    // Build the Fibonacci sequence iteratively
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Return the nth Fibonacci number
    return dp[n];
}
*/

int fib(int n) {
    if (n <= 1) {
        return n;
    }

    // Create a dp array to store Fibonacci numbers
    int pre1=1;
   int  pre2=0;

    // Initialize base cases
    

    // Build the Fibonacci sequence iteratively
    for (int i = 2; i <= n; i++) {
        int curr= pre1+pre2;
        pre2=pre1;
        pre1=curr;

    }

    // Return the nth Fibonacci number
    return pre1;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Fibonacci number at position " << n << " is " << fib(n) << endl;

    return 0;
}
