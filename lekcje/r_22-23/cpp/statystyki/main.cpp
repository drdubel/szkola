#include <bits/stdc++.h>
using namespace std;
string in;
int spacje() { return count(in.begin(), in.end(), ' '); }
bool czycyfra(char inp) { return (inp >= '0' && inp <= '9'); }
bool czylitera(char inp) {
    return ((inp >= 'a' && inp <= 'z') || (inp >= 'A' && inp <= 'Z'));
}
int liczby() {
    int out = 0;
    bool czypoprzedni = czycyfra(in[0]);
    for (int i = 1; i < (int)in.length(); ++i) {
        if (czypoprzedni && !czycyfra(in[i])) {
            czypoprzedni = 0;
            ++out;
        } else if (czycyfra(in[i]))
            czypoprzedni = 1;
    }

    if (czypoprzedni) ++out;
    return out;
}

int slowa() {
    int out = 0;
    bool czypoprzedni = czylitera(in[0]);
    for (size_t i = 1; i < in.length(); ++i) {
        if (czypoprzedni && !czylitera(in[i])) {
            czypoprzedni = 0;
            ++out;
        } else if (czylitera(in[i]))
            czypoprzedni = 1;
    }
    if (czypoprzedni) ++out;
    return out;
}

int zdania() {
    int out = 0;
    bool czyslowo = 0;
    for (auto c : in) {
        if (czylitera(c))
            czyslowo = 1;
        else if (c == '.' && czyslowo) {
            ++out;
            czyslowo = 0;
        } else if (c == '.')
            czyslowo = 0;
    }

    return out;
}

bool czypalindrom(string slowo) {
    for (auto &c : slowo) c = tolower(c);
    string rev = slowo;
    reverse(rev.begin(), rev.end());
    return (rev == slowo && slowo.length() > 0);
}

int palindromy() {
    string slowo;
    int out = 0;
    for (auto c : in) {
        if (czylitera(c))
            slowo += c;
        else {
            out += czypalindrom(slowo);
            slowo = "";
        }
    }

    out += czypalindrom(slowo);
    return out;
}

int wypisz(short n) {
    if (n == 1) return spacje();
    if (n == 2) return liczby();
    if (n == 3) return slowa();
    if (n == 4) return zdania();
    return palindromy();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    short kolejnosc[5];
    int i;
    for (i = 0; i < n; ++i) cin >> kolejnosc[i];
    getline(cin, in);
    getline(cin, in);
    for (i = 0; i < n; ++i) {
        cout << wypisz(kolejnosc[i]) << ' ';
    }
}
