#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
    int T;
    cin >> T;

    int arr[T][3];

    int save[T];

    for (int i = 0; i < T; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

        sort(arr[i], arr[i] + 3);
        save[i] = arr[i][1];
    }

    for (int i = 0; i < T; i++)
    {
        cout << "Case " << i + 1 << ": " << save[i] << "\n";
    }

    return 0;
}