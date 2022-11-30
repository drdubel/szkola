#include <iostream>

using namespace std;

int nwd(int liczba1, int liczba2) {
    while (liczba2 != 0) {
        swap(liczba1, liczba2);
        liczba2 = liczba2 % liczba1;
    }
    return liczba1;
}

int main() {
    int liczba1, liczba2;
    cin >> liczba1 >> liczba2;
    cout << nwd(liczba1, liczba2);
}