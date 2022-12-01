#include <iostream>
using namespace std;

int main() {
    int zakres_p, zakres_k;
    cin >> zakres_p >> zakres_k;
    if (zakres_p < zakres_k) {
        for (zakres_p; zakres_p <= zakres_k; zakres_p++) {
            cout << zakres_p << " ";
        }
    } else {
        for (zakres_p; zakres_p >= zakres_k; zakres_p--) {
            cout << zakres_p << " ";
        }
    }
    cout << "\n";
}