#include<iostream>
using namespace std;

void sayDigit(int n, string arr[])
{
    if (n == 0)
    {
        return;
    }
    
    int digit = n % 10;
    n = n / 10;
    
    sayDigit(n, arr); // Recursive call to handle previous digits
    
    cout << arr[digit] << " ";
}

int main()
{
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n;
    
    cout << "Enter the digit: ";
    cin >> n;
    
    cout << "Your number is: ";
    if (n == 0) {
        cout << arr[0]; // Handle the special case for zero
    } else {
        sayDigit(n, arr);
    }
    cout << endl;

    return 0;
}
