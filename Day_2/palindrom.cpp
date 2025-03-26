// // You are given a string 'S'. Your task is to check whether the string is palindrome or not.
//  For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.

// Note :

// String 'S' is NOT case sensitive

#include <bits/stdc++.h> 

using namespace std;

char toLower(char s) {
    if (s >= 'a' && s <= 'z') {
        return s;
    } else {
        char temp = s - 'A' + 'a'; // Convert to lowercase
        return temp;
    }
}

bool checkPalindrome(string s) {
    int st = 0;
    int ed = s.size() - 1;

    while (st <= ed) {
        if (!isalnum(s[st])) {
            st++; // Ignore non-alphanumeric characters from the start
        } else if (!isalnum(s[ed])) {
            ed--; // Ignore non-alphanumeric characters from the end
        } else {
            if (toLower(s[st]) != toLower(s[ed])) {
                return false;
            }
            st++;
            ed--;
        }
    }
    return true;
}

int main() {
    string S;
    cout << "Enter the string: ";
    getline(cin, S);

    if (checkPalindrome(S)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
