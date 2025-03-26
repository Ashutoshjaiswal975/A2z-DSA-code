/*Ninja was very fond of patterns. For a given integer ‘N’, he wants to make the N-Star Diamond.

Example:
Input: ‘N’ = 3

Output: 

  *
 ***
*****
*****
 ***
  *
  */


 void nStarDiamond(int n) {
  for(int i=1; i<=n; i++){
           
		for(int j=1; j<=n-i; j++){
			cout<<" ";
		}
		 for(int j=1; j<=2*i-1; j++){
             cout<<"*";
         }
        
        cout<<endl;
       
        
	}
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