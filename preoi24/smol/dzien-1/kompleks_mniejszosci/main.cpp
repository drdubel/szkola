#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> Range;

const int MAX_NODES = 1000000;
const int TREE_SIZE = (1 << 20);
vector<int> adjacencyList[MAX_NODES + 1];
Range nodeRange[MAX_NODES + 1];
int segmentTree[2 * TREE_SIZE];
int timer = 0;

void updateSegmentTree(int index) {
    index += TREE_SIZE;
    segmentTree[index] = 1;
    while (index > 1) {
        index /= 2;
        segmentTree[index] =
            segmentTree[2 * index] + segmentTree[2 * index + 1];
    }
}

int rangeQuery(int start, int end) {
    start += TREE_SIZE;
    end += TREE_SIZE;
    int sum = segmentTree[start];
    if (start != end) sum += segmentTree[end];
    while (start / 2 != end / 2) {
        if (start % 2 == 0) {
            sum += segmentTree[start + 1];
        }
        if (end % 2 == 1) {
            sum += segmentTree[end - 1];
        }
        start /= 2;
        end /= 2;
    }
    return sum;
}

void depthFirstSearch(int currentNode, int parentNode) {
    nodeRange[currentNode].first = ++timer;
    for (int neighbor : adjacencyList[currentNode]) {
        if (neighbor == parentNode) continue;
        depthFirstSearch(neighbor, currentNode);
    }
    nodeRange[currentNode].second = timer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int nodeCount;
    cin >> nodeCount;

    for (int i = 1; i < nodeCount; i++) {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        adjacencyList[nodeA].push_back(nodeB);
        adjacencyList[nodeB].push_back(nodeA);
    }

    depthFirstSearch(1, 1);

    for (int i = 1; i <= nodeCount; i++) {
        cout << rangeQuery(nodeRange[i].first, nodeRange[i].second) << "\n";
        updateSegmentTree(nodeRange[i].first);
    }
}
