#include<iostream>
using namespace std;
/*.........points...........
1.how to create dynamically 2d 
array with different row and col
2.input/output
3.how to free the heap memory
*/

int main(){
    int row;
    cout<<"enter the value of row"<<endl;
    cin>>row;


    int col;
    cout<<"enter the value of col"<<endl;
    cin>>col;


int **arr= new int*[row];

for(int i=0; i<row; i++){
    arr[i]= new int[col];
}
//creation done;

cout<<"enter the elements"<<endl;
//taking input of element
for (int i = 0; i <row; i++)
{
    for (int j = 0;j<col; j++)
    {
        cin>>arr[i][j];
    }
    
}

//for output
cout<<endl;
for (int i = 0; i <row; i++)
{
    for (int j = 0;j<col; j++)
    {
        cout<<arr[i][j]<<" ";
    }cout<<endl;
    
}


//releasing memory

for(int i=0; i<row; i++){
    delete [] arr[i];
}
delete []arr;




    return 0;
}