#include <deque>
#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 2e3 + 7;
int plansza[MAXN][MAXN][2], seg_i = 2;

struct Segment {
    int x, y;
};

void move_snake(deque<Segment> &snake, vector<int> &colors, char q) {
    int x = snake.back().x, y = snake.back().y;
    int ox = snake.front().x, oy = snake.front().y;

    switch (q) {
        case 'P':
            snake.push_back({x + 1, y});
            if (plansza[x + 1][y][0] != 0) {
                colors.push_back(plansza[x + 1][y][0]);
                plansza[x + 1][y][0] = 0;
            } else {
                snake.pop_front();
                plansza[ox][oy][1] = 0;
            }
            plansza[x + 1][y][1] = seg_i;
            break;

        case 'L':
            snake.push_back({x - 1, y});
            if (plansza[x - 1][y][0] != 0) {
                colors.push_back(plansza[x - 1][y][0]);
                plansza[x - 1][y][0] = 0;
            } else {
                snake.pop_front();
                plansza[ox][oy][1] = 0;
            }
            plansza[x - 1][y][1] = seg_i;
            break;

        case 'D':
            snake.push_back({x, y + 1});
            if (plansza[x][y + 1][0] != 0) {
                colors.push_back(plansza[x][y + 1][0]);
                plansza[x][y + 1][0] = 0;
            } else {
                snake.pop_front();
                plansza[ox][oy][1] = 0;
            }
            plansza[x][y + 1][1] = seg_i;
            break;

        case 'G':
            snake.push_back({x, y - 1});
            if (plansza[x][y - 1][0] != 0) {
                colors.push_back(plansza[x][y - 1][0]);
                plansza[x][y - 1][0] = 0;
            } else {
                snake.pop_front();
                plansza[ox][oy][1] = 0;
            }
            plansza[x][y - 1][1] = seg_i;
            break;
    }

    ++seg_i;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, p, n, x, y, c;
    deque<Segment> snake;
    vector<int> colors;
    char q;

    cin >> m >> p >> n;

    for (int i = 0; i < p; i++) {
        cin >> y >> x >> c;
        plansza[x][y][0] = c + 1;
    }

    plansza[1][1][1] = 1;
    snake.push_back({1, 1});
    colors.push_back(1);

    for (int i = 0; i < n; i++) {
        cin >> q;

        if (q == 'Z') {
            cin >> y >> x;
            if (plansza[x][y][1])
                cout << colors[plansza[x][y][1] - (seg_i - snake.size())] - 1
                     << "\n";
            else
                cout << "-1\n";
        } else {
            move_snake(snake, colors, q);
        }
    }

    return 0;
}
