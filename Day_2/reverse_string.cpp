#include<iostream>
using namespace std;

int reverse(char name[], int n) {
    int s=0;
    int e=n-1;
   while(s<=e)
   {
    swap(name[s], name[e]);
    s++;
    e--;
   }
   
}

int main() {
    int n;
    cout << "Enter the size of the string: ";
    cin >> n;

    // Dynamically allocate memory for the string
    char* str = new char[n];

    cout << "Enter the string: ";
    cin >> str;
    

    reverse(str, n);

    // Output the length of the string
    cout << "reverse of the string: " << str << endl;

    // Free the allocated memory
    

    return 0;
}