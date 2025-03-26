  #include<iostream>
  using namespace std;

void arr(int a[],int size )
{
    cout<<"printing the array"<< endl;
    for (int i = 0; i < size; i++)
    {
        cout<< a[i] <<" "<<  endl;

    }
    cout<<"printing done"<<endl;
}


  int main(){
    int ashu[10]={1,2,3,4,5};
    
  
  arr(ashu, 5);
  
int ashusize=sizeof(ashu)/sizeof(int);
cout<<" size of ashu is " <<ashusize;



  return 0;
  }