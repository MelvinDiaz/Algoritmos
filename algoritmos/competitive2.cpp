#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}

int main()
{

    int m, n, l = 0;
    int cont = 0;
    int finalResult[100];
    bool iterator = true;

    while (iterator)
    {

        scanf("%d %d", &n, &m);

        if (n == 0 && m == 0)
        {
            iterator = false;
        }
        

        int aliceCards[n];
        int bettyCards[m];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &aliceCards[i]);
        }

        for (int i = 0; i < m; i++)
        {

            scanf("%d", &bettyCards[i]);
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (i == (n - 1))
            {
                break;
            }

            if (aliceCards[i] == aliceCards[i + 1])
            {
                aliceCards[i] = 0;
            }
        }

        for (int i = 0; i < m - 1; i++)
        {
            if (i == (m - 1))
            {
                break;
            }

            if (bettyCards[i] == bettyCards[i + 1])
            {
                bettyCards[i] = 0;
            }
        }

        quickSort(aliceCards, 0, n - 1);
        quickSort(bettyCards, 0, m - 1);

        int aux = 0;
        if (n > m)
        {
            for (int i = 0; i < m; i++)
            {
                int aux = 0;
                if (bettyCards[i] == 0)
                {
                    continue;
                }
                else
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (aliceCards[j] == 0)
                        {
                            continue;
                        }
                        else
                        {
                            if (aliceCards[j] == bettyCards[i])
                            {
                                aux = 0;
                                break;
                            }

                            else if (aliceCards[j] != bettyCards[i])
                            {
                                aux++;
                                continue;
                            }
                        }
                    }
                }
                if (aux != 0)
                {
                    cont++;
                }
            }
        }
        else if (m >= n)
        {
            for (int i = 0; i < n; i++)
            {
                int aux = 0;
                if (aliceCards[i] == 0)
                {
                    continue;
                }
                else
                {
                    for (int j = 0; j < m; j++)
                    {
                        if (bettyCards[j] == 0)
                        {
                            continue;
                        }
                        else
                        {
                            if (bettyCards[j] == aliceCards[i])
                            {
                                aux = 0;
                                break;
                            }
                            else if (bettyCards[j] != aliceCards[i])
                            {
                                aux++;
                                continue;
                            }
                        }
                    }
                }
                if (aux != 0)
                {
                    cont++;
                }
            }
        }
        if (m != 0 && n != 0)
        {
            finalResult[l] = cont;
            printf("%d\n", finalResult[l]);
            cont = 0;
            l++;
        }
    }

    return 0;
}