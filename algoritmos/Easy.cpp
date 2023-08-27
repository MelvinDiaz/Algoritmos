#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int month, n;
    float dpay, loan;

    while ((cin >> month >> dpay >> loan >> n), month >= 0)
    {
        float carValue = dpay + loan;
        float payments[n][2];
        int cont = 0;

        for (int i = 0; i < n; i++)
        {
            double x, y;
            cin >> payments[i][0] >> payments[i][1];
        }
        float monthPayment = loan / month;
        for (int i = 0; i < month; i++)
        {

            double rest = (payments[i + 1][0] - payments[i][0]);
            if (rest < 0)
            {
                rest = month - payments[i][0];
            }

            for (int j = 0; j < rest; j++)
            {

                loan = loan - monthPayment;

                carValue = (carValue) - (carValue * payments[i][1]);

                if (carValue > loan)
                {
                    cont++;
                    if (cont == 1)
                    {
                        
                        cout << cont << " month" << endl;
                    }
                    else
                    {
                        
                        cout << cont << " months" << endl;
                    }
                    break;
                }
                cont++;
            }
            if (carValue > loan)
            {
                break;
            }
        }
    }

    return 0;
}