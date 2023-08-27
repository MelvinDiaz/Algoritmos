#include <iostream>
// #include <string>
using namespace std;

int main()
{
    int k, n, m;

    string save[1000];
    int cont = 0;

    while (cin >> k && k != 0)
    {
        cin >> n >> m;

        for (int i = 0; i < k; i++)
        {
            int x, y;

            cin >> x >> y;

            if (x == n || y == m)
            {
                save[i] = "divisa";
            }
            else if (x > n && y > m)
            {
                save[i] = "NE";
            }
            else if (x < n && y < m)
            {
                save[i] = "SO";
            }
            else if (x > n && y < m)
            {
                save[i] = "SE";
            }
            else if (x < n && y > m)
            {
                save[i] = "NO";
            }
        }
        for (int i = 0; i < k; i++)
        {
            cout << save[i] << "\n";
        }
    }

    return 0;
}