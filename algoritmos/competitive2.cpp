#include <iostream>
using namespace std;

int main()
{

    int m, n, l = 0;
    int finalResult[100];

    while (n != 0 && m != 0)
    {
        cin >> n >> m;
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

        int cont = 0;

        if (m > n)
        {
            for (int i = 0; i < m; i++)
            {
                int aux = 0;
                for (int j = 0; j < n; j++)
                {
                    if (aliceCards[j] == aliceCards[j + 1])
                    {
                        i++;
                    }
                    else if (bettyCards[i] == aliceCards[j])
                    {
                        aux = 0;
                        i++;
                    }
                    else if (aliceCards[j] != bettyCards[i])
                    {
                        i++;
                        aux++;
                    }
                }
                cont += aux;
            }
        }
        else if (n > m)
        {
            for (int i = 0; i < n; i++)
            {
                int aux = 0;
                for (int j = 0; j < m; j++)
                {
                    if (bettyCards[j] == bettyCards[j + 1])
                    {
                        i++;
                    }

                    else if (bettyCards[i] == aliceCards[j])
                    {
                        aux = 0;
                        i++;
                    }
                    else if (aliceCards[j] != bettyCards[i])
                    {
                        i++;
                        aux++;
                    }
                }
                cont += aux;
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                int aux = 0;
                for (int j = 0; j < m; j++)
                {

                    if (bettyCards[j] == aliceCards[i])
                    {
                        aux = 0;
                        i++;
                    }
                    else
                    {
                        i++;
                        aux++;
                    }
                }
                cont += aux;
            }
            if (m > n)
            {
                --cont;
            }
        }

        finalResult[l] = cont;
        l++;
    }

    for (int i = 0; i < (l - 1); i++)
    {
        cout << finalResult[i] << endl;
    }

    return 0;
}