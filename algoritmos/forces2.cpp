#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string data[n];

    if (n >= 1 && n <= 100)
    {
        for (int i = 0; i < n; i++)
        {
            string dataAux;
            cin >> dataAux;
            int size = dataAux.length();

            if (size <= 10)
            {
                data[i] = dataAux;
            }
            else
            {
                data[i] = dataAux[0] + to_string(size - 2) + dataAux[size - 1];
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << data[i] + "\n";
        }
    }

    return 0;
}