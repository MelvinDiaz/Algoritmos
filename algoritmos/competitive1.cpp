#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

int main()
{
    int n;

    scanf("%d", &n);
    //char response[n+1][3];
    std::vector<std::string> response;
    for (int p = 1; p <= n; p++)
    {
        int y = 0;
        int x, current;
        char card[52][3];
        for (int i = 1; i <= 52; i++)
        {
            scanf("%s", card[i]);
        }

        int positions = 27;

        for (int i = 1; i <= 3; i++, --positions)
        {
            current = card[positions][0] - '0';
            if (current < 2 || current > 9)
            {
                current = 10;
            }

            positions = positions - (10 - current);

            y += current;
        }

        int final = positions + 25;

        char finalArray[final][3];

        for (int i = 1; i <= positions; i++)
        {
            strcpy(finalArray[i], card[i]);
        }

        int counter = 28;
        for (int i = (positions + 1); i <= final; i++, counter++)
        {
            strcpy(finalArray[i], card[counter]);
        }

        //std::cout << finalArray[y] << std::endl;
        response.push_back(finalArray[y]);
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << "Case " << (i+1) << ": " << response[i] << std::endl;
    }
    
}