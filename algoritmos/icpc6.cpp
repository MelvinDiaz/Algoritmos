#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> m >> n;

    int area = n * m;

    int dominoes = area / 2;

    cout << dominoes;
}