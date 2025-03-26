#include<iostream>
using namespace std;

int power(int base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }
    int smallerPblm = power(base, exponent - 1);
    int biggerPblm = base * smallerPblm;

    return biggerPblm;
}

int main()
{
    int base, exponent;
    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exponent;

    int ans = power(base, exponent);
    cout << "The result is: " << ans << endl;

    return 0;
}

