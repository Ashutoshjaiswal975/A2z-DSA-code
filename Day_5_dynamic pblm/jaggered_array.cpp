#include <iostream>
using namespace std;

int main() {
    int row;
    cout << "Enter the value of row: ";
    cin >> row;

    // Creating a jagged array where each row can have a different number of columns
    int **arr = new int*[row];
    int *colSizes = new int[row]; // To store the number of columns in each row

    for (int i = 0; i < row; i++) {
        cout << "Enter the number of columns for row " << i + 1 << ": ";
        cin >> colSizes[i];
        arr[i] = new int[colSizes[i]];
    }
    // Creation done

    cout << "Enter the elements:" << endl;
    // Taking input of elements
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colSizes[i]; j++) {
            cin >> arr[i][j];
        }
    }

    // For output
    cout << endl << "The jagged array is:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colSizes[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Releasing memory
    for (int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] colSizes;

    return 0;
}
