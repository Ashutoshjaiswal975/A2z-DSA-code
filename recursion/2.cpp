/*
Input:
5
Output:
GFG GFG GFG GFG GFG
*/

  void printGfg(int N) {
        if(N==0){
            return;
        }
        
        cout<<"GFG"<<" ";
        printGfg(N-1);
    }