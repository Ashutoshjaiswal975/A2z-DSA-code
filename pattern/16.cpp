
/* 
Sam is curious about Alpha-Ramp, so he decided to create Alpha-Ramp of different sizes.

An Alpha-Ramp is represented by a triangle, where alphabets are filled from the top in order.

For every value of ‘N’, help sam to return the corresponding Alpha-Ramp.

Example:
Input: ‘N’ = 3

Output: 
A
B B
C C C
*/


void alphaRamp(int n) {
   for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout<<char('A'+i)<<" ";
        }
        cout<<endl;
    }
}