#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    int k, n;
    int contador = 0;
    string arr;

    cin >> n >> k;
    int numbers[n];

    cin.ignore();
    getline(cin, arr);

    istringstream iss(arr);

    if (k == n)
    {
        contador = n;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            iss >> numbers[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (numbers[i] > k)
            {
                if (numbers[i] >= numbers[k - 1])
                    contador++;
            }
        }
    }

    cout << contador;
}