/*Problem statement
Sam is making a forest visualizer. An N-dimensional forest is represented by the pattern of size NxN filled with ‘*’.

For every value of ‘N’, help sam to print the corresponding N-dimensional forest.

Example:
Input: ‘N’ = 3

Output: 
* * *
* * *
* * *
*/


void nForest(int n) {
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout<<"*"<<" ";
		}
		cout<<endl;
	}
}
