// Problem statement
// Ninja was very fond of patterns. For a given integer ‘N’, he wants to make the Reverse N-Star Triangle.

// Example:
// Input: ‘N’ = 3

// Output: 

// *****
//  ***
//   * 


void nStarTriangle(int n) {
for(int i=1; i<=n; i++){
    for(int j=1; j<=i-1; j++){
			cout<<" ";
		}
           
            for(int j=1; j<=2 * (n - i) + 1; j++){
             cout<<"*";
         }
		
        
        cout<<endl;
        
	}
}