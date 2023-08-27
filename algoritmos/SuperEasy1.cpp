#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int arr[t][2];
    char save[t];
    for (int i = 0; i < t; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        if (arr[i][0] == arr[i][1])
        {
            save[i] = '=';
        }
        else
        {
            save[i] = (arr[i][0] > arr[i][1]) ? '>' : '<';
        }
    }

    for (int i = 0; i < t; i++)
    {
        cout << save[i] << "\n";
    }
}