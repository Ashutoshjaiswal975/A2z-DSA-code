#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n = 0;
    cout << "enter the value: " << endl;
    cin >> n;

    int count = 0;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            count++;
            for (int j = 2 * i; j < n; j = j + i)
            {
                prime[j] = 0;
            }
        }
    }

    for (int i = 2; i <= n; i++) // Count prime numbers up to n
    {
        if (prime[i])
        {
            count++;
        }
    }

    cout << "Number of prime numbers less than or equal to " << n << ": " << count << endl;

    return 0;
}