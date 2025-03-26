#include<iostream>
using namespace std;

int getLength(char name[]) {
    int count = 0;
    for (int i = 0; name[i] != 0; i++) {
        count++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the size of the string: ";
    cin >> n;

    // Dynamically allocate memory for the string
    char* str = new char[n];

    cout << "Enter the string: ";
    cin >> str;
    cout<< " you are my "<< str<<endl;

    // Call the function to get the length of the string
    int length = getLength(str);

    // Output the length of the string
    cout << "Length of the string: " << length << endl;

    // Free the allocated memory
    

    return 0;
}
