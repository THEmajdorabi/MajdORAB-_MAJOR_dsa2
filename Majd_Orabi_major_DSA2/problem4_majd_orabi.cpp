#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int first, second;
};

bool compare(Pair a, Pair b) {
    return a.second < b.second;
}

int maxChainLen(vector<Pair>& pairs) {
    sort(pairs.begin(), pairs.end(), compare);
    int count = 1;
    Pair last = pairs[0];

    for (const auto& p : pairs) {
        if (p.first > last.second) {
            count++;
            last = p;
        }
    }

    return count;
}

int main() {
    vector<Pair> pairs = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    cout << "Example 1 Input: {5 24, 39 60, 15 28, 27 40, 50 90}" << endl;
    cout << "Example 1 Output: " << maxChainLen(pairs) << endl;

    pairs = {{5, 10}, {1, 11}};
    cout << "Example 2 Input: {5 10, 1 11}" << endl;
    cout << "Example 2 Output: " << maxChainLen(pairs) << endl;

    return 0;
}
