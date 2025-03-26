#include <iostream>
using namespace std;

class TwoStack {
    int* arr;
    int top1;
    int top2;
    int size;

public:
    // Initialize TwoStack.
    TwoStack(int s) {
        size = s;
        arr = new int[s];
        top1 = -1;          // Stack 1 starts from the left (index -1 means empty)
        top2 = size;        // Stack 2 starts from the right (index size means empty)
    }

    // Push in stack 1.
    void push1(int num) {
        if (top1 < top2 - 1) {
            top1++;
            arr[top1] = num;
        } else {
            cout << "Stack 1 Overflow by element: " << num << endl;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if (top2 > top1 + 1) {
            top2--;
            arr[top2] = num;
        } else {
            cout << "Stack 2 Overflow by element: " << num << endl;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if (top1 >= 0) {
            int poppedElement = arr[top1];
            top1--;
            return poppedElement;
        } else {
            cout << "Stack 1 U nderflow" << endl;
            return -1; // Return -1 to indicate underflow
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if (top2 < size) {
            int poppedElement = arr[top2];
            top2++;
            return poppedElement;
        } else {
            cout << "Stack 2 Underflow" << endl;
            return -1; // Return -1 to indicate underflow
        }
    }

    // Destructor to avoid memory leaks
    ~TwoStack() {
        delete[] arr;
    }
};

int main() {
    TwoStack ts(10);

    ts.push1(5);
    ts.push2(10);
    ts.push1(15);
    ts.push2(20);

    cout << ts.pop1() << endl; // Should print 15
    cout << ts.pop2() << endl; // Should print 20
    cout << ts.pop1() << endl; // Should print 5
    cout << ts.pop2() << endl; // Should print 10

    return 0;
}
