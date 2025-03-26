#include <iostream>
using namespace std;

bool isPalindrome(string &str, int start, int end)
{
    // Base case: if the string is empty or a single character
    if (start >= end)
    {
        return true;
    }

    // Check if the characters at the start and end match
    if (str[start] != str[end])
    {
        return false;
    }

    // Recursive call to check the rest of the string
    return isPalindrome(str, start + 1, end - 1);
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    bool result = isPalindrome(input, 0, input.length() - 1);

    if (result)
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
