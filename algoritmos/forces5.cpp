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

    int aux = 0;
    for (int i = 0; i < n; i++)
    {
        iss >> numbers[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (numbers[i] == numbers[i + 1])
        {
            aux++;
        }

        if (numbers[i] >= numbers[k - 1] && numbers[i] > 0)
            contador++;
        if (aux == n)
        {
            contador = n;
        }
    }

    cout << contador;
}