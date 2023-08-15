#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int v, h, s, k, travel;
    cin >> h >> k >> v >> s;

    while (h > 0)
    {

        v = v + s;
        int dec = ceil(v / 10);

        v = v - max(1, dec);
        if (v >= k)
            h++;

        if (0 < v && v < k)
        {
            h--;
            if (h == 0)
                v = 0;
        }
        if (v <= 0)
        {
            h = 0;
            v = 0;
        }

        travel = travel + v;
        if (s > 0)
            s--;

        
    }

    cout << travel;
}