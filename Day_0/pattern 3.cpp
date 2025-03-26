#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "enter the no of line: ";
    cin >> n;
    int i = 1;
    int k = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= n){
            cout << k << " ";
            k = k + 1;
            j = j + 1;
        }
        cout << endl;
        i = i + 1;
    }

    return 0;
}