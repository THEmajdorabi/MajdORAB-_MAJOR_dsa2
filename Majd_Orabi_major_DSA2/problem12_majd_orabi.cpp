#include <iostream>
#include <vector>

using namespace std;

int numberSequence(int m, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int j = 1; j <= m; j++) {
        dp[1][j] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = j * 2; k <= m; k += j) {
                dp[i][k] += dp[i - 1][j];
            }
        }
    }

    int total = 0;
    for (int j = 1; j <= m; j++) {
        total += dp[n][j];
    }
    return total;
}

int main() {
    int m = 10, n = 4;
    cout << "Example 1 Input: m = 10, n = 4" << endl;
    cout << "Example 1 Output: " << numberSequence(m, n) << endl;

    m = 5; n = 2;
    cout << "Example 2 Input: m = 5, n = 2" << endl;
    cout << "Example 2 Output: " << numberSequence(m, n) << endl;

    return 0;
}
