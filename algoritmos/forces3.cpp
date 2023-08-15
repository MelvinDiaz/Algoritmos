#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    string arr[n][3];
    int solvCon = 0;
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        string help;
        getline(cin, help);

        arr[i][0] = help[0];
        arr[i][1] = help[2];
        arr[i][2] = help[4];
    }

    for (int i = 0; i < n; i++)
    {

        if (arr[i][0] == "1")
            cont++;
        if (arr[i][1] == "1")
            cont++;
        if (arr[i][2] == "1")
            cont++;

        if (cont > 1)
            solvCon++;

        cont = 0;
    }

    cout << solvCon;
    return 0;
}