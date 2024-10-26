/*  Question 1:-Geek is learning a new programming language. As data type forms the most fundamental part of a language, Geek is learning them with focus and needs your help.
Given a data type, help Geek in finding the size of it in byte.

Data Type - Character, Integer, Long, Float and Double

Example 1:

Input: Character
Output: 1
Explaination: For java it would be 2 bytes.*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    int dataTypeSize(string str) {
        if (str == "int") {
            return sizeof(int);
        } else if (str == "float") {
            return sizeof(float);
        } else if (str == "char") {
            return sizeof(char);
        } else if (str == "double") {
            return sizeof(double);
        } else if (str == "long") {
            return sizeof(long);
        } else {
            return -1; // Return -1 if the type is unknown
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.dataTypeSize(str);
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
