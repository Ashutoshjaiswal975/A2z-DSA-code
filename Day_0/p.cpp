#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int i = n;
    while (i >=1 ) {
        int j = 1;
        while (j <= i) {
            cout << j;
            j++;
        }
        cout << endl;
        i--;
    }

    return 0;
}



