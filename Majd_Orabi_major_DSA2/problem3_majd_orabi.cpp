#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.deadline < b.deadline;
}

pair<int, int> jobSchedulingDP(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);

    int n = jobs.size();
    vector<int> dp(n); 
    for (int i = 0; i < n; i++) {
        dp[i] = jobs[i].profit; 
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (jobs[i].deadline > jobs[j].deadline && dp[i] < dp[j] + jobs[i].profit) {
                dp[i] = dp[j] + jobs[i].profit;
            }
        }
    }

    int maxProfit = *max_element(dp.begin(), dp.end());
    int countJobs = 0;
    for (int profit : dp) {
        if (profit == maxProfit) countJobs++; 
    }

    return {countJobs, maxProfit};
}

int main() {
    vector<Job> jobs = {{1, 2, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    cout << "Example 1 Input: {1, 2, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}" << endl;
    auto result = jobSchedulingDP(jobs);
    cout << "Example 1 Output: " << result.first << " " << result.second << endl;

    jobs = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}};
    cout << "Example 2 Input: {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}" << endl;
    result = jobSchedulingDP(jobs);
    cout << "Example 2 Output: " << result.first << " " << result.second << endl;

    return 0;
}
