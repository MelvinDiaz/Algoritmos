#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long int n, m, a;
    long long int response;

    cin >> n >> m >> a;

    long long int flagsAlongN = (n + a - 1) / a;
    long long int flagsAlongM = (m + a - 1) / a;

    response = flagsAlongN * flagsAlongM;

    cout << response;

    return 0;
}