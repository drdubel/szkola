#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int il_ciec;
    cin >> il_ciec;
    int il_kawalkow = pow(2, floor(log2(il_ciec)) + 1);
    cout << il_kawalkow << "\n";
}