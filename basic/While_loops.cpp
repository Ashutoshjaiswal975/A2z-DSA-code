/*While loop is another loop like for loop but unlike for loop it only checks for one condition.
Here, we will use a while loop and print a number n's table in reverse order.

Examples:

Input: 1
Output: 10 9 8 7 6 5 4 3 2 1
Input: 2
Output: 20 18 16 14 12 10 8 6 4 2*/


class Geeks {
	 static void printTable (int n) 
	 {
            int multiplier=10;
            while(multiplier>=1)
            {
            //   int q = n * multiplier;
            System.out.print(n * multiplier +" ");
            multiplier--;
            }
            System.out.println();
      
	 }

}