#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            cout << " ";
        }

        for (int k = 0; k < i * 2 + 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            cout << " ";
        }

        for (int k = 0; k < i * 2 + 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
