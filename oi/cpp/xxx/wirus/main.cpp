#include <iostream>

using namespace std;

void change_genotype(long long n, long long d, string first_genotype) {
    bool prev_genotype[n], genotype[n], same;

    for (int i = 0; i < n; i++) {
        genotype[i] = first_genotype[i] - 48;
        prev_genotype[i] = first_genotype[i] - 48;
    }

    for (long long i = 1; i <= d; i++) {
        same = true;

        for (int j = 0; j < n - 1; j++) {
            if (prev_genotype[j] == prev_genotype[j + 1]) {
                genotype[n - 1 - j] = 0;
            } else {
                genotype[j] = 1;
            }
        }

        for (int j = 0; j < n; j++) {
            if (first_genotype[j] != genotype[j]) {
                same = false;
                break;
            }
        }

        if (same) {
            change_genotype(n, d % (i - 1 ? i - 1 : i), first_genotype);
            return;
        }

        for (int j = 0; j < n; j++) {
            prev_genotype[j] = genotype[j];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << genotype[i];
    }
}

int main() {
    long long n, d;
    string genotype;

    cin >> n >> d >> genotype;

    change_genotype(n, d, genotype);

    return 0;
}