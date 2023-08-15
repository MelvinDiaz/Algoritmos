#include <iostream>

int main()
{
    int w;
    std::cin >> w;

    if (w >= 1 || w <= 100)
    {
        if ((w % 2) != 0)
        {
            std::cout << "NO";
        }
        else
        {
            int n = w / 2;
            if (n == 1)
            {
                std::cout << "NO";
            }
            else
            {
                std::cout << "YES";
            }
        }
    }
    else
    {
        std::cout << "NO";
    }
    return 0;
}