#include <iostream>
using namespace std;

class Heap
{
private:
    int *arr;
    int capacity;
    int size;

public:
    void heapify(int arr[], int N, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < N && arr[left] > arr[largest])
        {
            largest = left;
        }

        if (right < N && arr[right] > arr[largest])
        {
            largest = right;
        }

        // if largest is not root, or it was changed
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, N, largest);
        }
    }

    void buildMaxHeap()
    {
        for (int i = size / 2 - 1; i >= 0; --i)
            heapify(arr, size, i);
    }

    void heapSort(int A[], int N)
    {
        arr = A;
        size = N;
        //Function that builds the initial heap from the unsorted array
        buildMaxHeap();

        for (int i = size - 1; i > 0; --i)
        {
            // Moves the root to the end of the array
            swap(arr[0], arr[i]);
            // Heapify the reduced heap
            heapify(arr, i, 0);
        }
    }

    void printArray()
    {
        for (int i = 0; i < size; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};