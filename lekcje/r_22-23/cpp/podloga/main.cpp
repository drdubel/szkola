#include <iostream>
using namespace std;

int main() {
    string klocki;
    cin >> klocki;
    cout << ((int)klocki[0] - '0') * ((int)klocki[klocki.size() - 1] - '0')
         << "\n";
}
