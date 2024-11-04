/* 
Problem statement
Sam is curious about Alpha-Hills, so he decided to create Alpha-Hills of different sizes.

An Alpha-hill is represented by a triangle, where alphabets are filled in palindromic order.

For every value of ‘N’, help sam to return the corresponding Alpha-Hill.

Example:
Input: ‘N’ = 3

Output: 
    A
  A B A
A B C B A

*/


void alphaHill(int n) {
    for(int i=0;i<n;i++){
          
          // for printing the spaces.
          for(int j=0;j<n-i-1;j++){
              cout<<" ";
          }
          
          // for printing the characters.
          char ch = 'A';
          int breakpoint = (2*i+1)/2;
          for(int j=1;j<=2*i+1;j++){
              
              cout<<ch<<" ";
              if(j <= breakpoint) ch++;
              else ch--;
          }
          
          // for printing the spaces again after characters.
          for (int j = 0; j < n - i - 1; j++) {
              cout << " ";
          }

          // As soon as the letters for each iteration are printed, we move to
          // the next row and give a line break otherwise all letters would get
          // printed in 1 line.
          cout << endl;
    }
}