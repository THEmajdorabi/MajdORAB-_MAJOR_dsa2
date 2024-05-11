#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int first, second;
};

bool compare(Pair a, Pair b) {
    return a.first < b.first;
}

int maxChainLenDP(vector<Pair>& pairs) {
    sort(pairs.begin(), pairs.end(), compare);
    int n = pairs.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (pairs[j].second < pairs[i].first) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<Pair> pairs = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    cout << "Example 1 Input: {5 24, 39 60, 15 28, 27 40, 50 90}" << endl;
    cout << "Example 1 Output: " << maxChainLenDP(pairs) << endl;

    pairs = {{5, 10}, {1, 11}};
    cout << "Example 2 Input: {5 10, 1 11}" << endl;
    cout << "Example 2 Output: " << maxChainLenDP(pairs) << endl;

    return 0;
}
