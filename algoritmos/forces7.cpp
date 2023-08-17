#include <iostream>
using namespace std;

int main()
{

    int matrix[5][5];
    int first, second, third, fourth, fifth;
    int x, y;
    int contX = 0;
    int contY = 0;
    int contSum = 0;

    for (int i = 1; i <= 5; i++)
    {
        cin >> first >> second >> third >> fourth >> fifth;
        matrix[i][1] = first;
        matrix[i][2] = second;
        matrix[i][3] = third;
        matrix[i][4] = fourth;
        matrix[i][5] = fifth;
    }

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {

            if (matrix[i][j] == 1)
            {
                x = j;
                y = i;
            }
        }
    }

    // for
    for (int i = 0; i < 5; i++)
    {
        if (x == 3)
        {
            i = 5;
        }
        else if (x < 3)
        {
            x++;
            contSum++;
        }
        else if (x > 3)
        {
            x--;
            contSum++;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (y == 3)
        {
            i = 5;
        }
        else if (y < 3)
        {
            y++;
            contSum++;
        }
        else if (y > 3)
        {
            y--;
            contSum++;
        }
    }

    cout << contSum;

    return 0;
}