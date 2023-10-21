#include <iostream>
using namespace std;

// Partition will return the index where the pivot will be in sorted order.
int partition(int A[], int low, int high)
{
    // We take the last element as the pivot.
    int pivot = A[high];

    int i = low - 1; // Index of smaller element.

    // We iterate through the array,
    for (int j = low; j <= high - 1; ++j)
    {
        // If the current element is smaller than the pivot, we swap the element thats smaller with the i'th element.
        if (A[j] < pivot)
        {
            ++i;
            swap(A[i], A[j]);
        }
    }

    // Last swap.
    swap(A[i + 1], A[high]);
    return i + 1;
}

void quickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(A, low, high); // Te result will be the index where the pivot will be.
        // Call for the left side of the pivot final position.
        quickSort(A, low, pivot - 1);
        // Call for the right side of the pivot final position.
        quickSort(A, pivot + 1, high);
    }
}

int main()
{
    int A[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "Unsorted array: \n";

    for (int i = 0; i < n; ++i)
    {
        cout << A[i] << " ";
    }
    cout << "\n";

    quickSort(A, 0, n - 1);
    cout << "Sorted array: \n";

    for (int i = 0; i < n; ++i)
    {
        cout << A[i] << " ";
    }
    cout << "\n";

    return 0;
}