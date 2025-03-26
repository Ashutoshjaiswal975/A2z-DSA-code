#include <iostream>
#include <stack>
using namespace std;

class mystack
{

    // properties
public:
    int *arr;
    int top;
    int size;

    // behaviour
    mystack(int size)
    {

        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "stack is overflow" << endl;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << " stack underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0 && top < size)
        {
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }

    bool isempty()
    {
        if(top== -1){
            return true;
        }
        else{
            false;
        }
    }
};

int main()
{

    mystack st(5);
    st.push(1);
    st.push(2);
    st.push(3);

    cout<<st.peek()<<endl;



    // // creation of stack
    // stack<int> s;

    // // push operation
    // s.push(10);
    // s.push(11);
    // cout << s.top() << endl;
    // // pop operation
    // s.pop();
    // cout << s.top() << endl;

    // if (s.empty())
    // {
    //     cout << " it is empty" << endl;
    // }
    // else
    // {
    //     cout << "not empty" << endl;
    // }

    return 0;
}