#include <iostream>
using namespace std;

int main()
{

    int A[5] = {5, 2, 6, 1, 3};

    int i, key, j;
    int n = sizeof(A) / sizeof(A[0]);

    for (j = 0; j < n; j++)
    {
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}