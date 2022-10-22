#include <iostream>
#include <cmath>
using namespace std;


void wyp_dzielniki(int liczba) {
	for (int i=1; i <= sqrt(liczba); i++) {
		if (liczba%i == 0) {
			cout << i << " ";
			if (liczba/i != i) {
                cout << liczba/i << " ";
            }
		}
	}
}


int main() {
	int liczba;
	cin >> liczba;
	wyp_dzielniki(liczba);
	cout << "\n";
}
