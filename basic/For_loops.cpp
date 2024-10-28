function findNthFibonacci(n) {
    if (n == 1|| n==2) {
        return 1;
    }
    
   
    return findNthFibonacci(n - 1) + findNthFibonacci(n - 2);
}