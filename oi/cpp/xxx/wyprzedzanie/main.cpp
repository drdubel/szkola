#include <algorithm>
#include <iostream>

using namespace std;

constexpr int MAXN = 1e5 + 7;

struct Truck {
    int d = 0, w, m;
    double v, x;
};

double* move_trucks(Truck* trucks, double time, int n) {
    static double new_positions[MAXN];

    new_positions[n] = 1e9 + 7;
    for (int i = n - 1; i >= 0; i--) {
        Truck truck = trucks[i];

        new_positions[i] = min(truck.x + time * truck.v,
                               new_positions[i + 1] - trucks[i + 1].d);
    }

    return new_positions;
}

int count_lane_changes(Truck trucks[], int n, int D, int W, int M, double V) {
    int lane_changes = 0;
    bool right_lane = true;

    for (int i = 0; i < n; i++) {
        Truck truck = trucks[i];

        double time = (truck.x - truck.d) / (V - truck.v);
        double* new_positions = move_trucks(trucks, time, n);

        if (!right_lane) {
            if ((new_positions[i] - truck.d) - new_positions[i - 1] >= D) {
                right_lane = true;
            }
        }

        if (right_lane) {
            lane_changes++;
            right_lane = false;
        }

        time = (truck.x + D) / (V - truck.v);
        new_positions = move_trucks(trucks, time, n);

        if ((new_positions[i + 1] - truck.d) - new_positions[i] >= D) {
            right_lane = true;
        }
    }

    return lane_changes;
}

int main() {
    int n, D, W, M;
    double V;
    Truck trucks[MAXN], truck;

    cin >> n >> D >> W >> M;

    V = (double)W / (double)M;

    for (int i = 0; i < n; i++) {
        cin >> truck.x >> truck.d >> truck.w >> truck.m;

        truck.v = (double)truck.w / (double)truck.m;
        trucks[i] = truck;
    }

    int lane_changes = count_lane_changes(trucks, n, D, W, M, V);

    cout << lane_changes << "\n";
}
