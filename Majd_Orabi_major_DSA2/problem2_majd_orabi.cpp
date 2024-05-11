#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

struct Job {
    int id, deadline, profit;
};

// Sort jobs based on their deadlines
bool jobComparator(const Job &a, const Job &b) {
    return a.deadline < b.deadline;
}

pair<int, int> jobScheduling(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), jobComparator); // Sort jobs by deadlines
    int count = 0, profit = 0;
    vector<int> timeLine(jobs.back().deadline + 1, -1); // Timeline to keep track of job scheduling

    for (const auto& job : jobs) {
        for (int t = job.deadline; t > 0; t--) {
            if (timeLine[t] == -1) { // If the slot is free
                timeLine[t] = job.id;
                count++;
                profit += job.profit;
                break;
            }
        }
    }

    return {count, profit};
}

int main() {
    vector<Job> jobs = {{1, 2, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    cout << "Example 1 Input: {1, 2, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}" << endl;
    auto result = jobScheduling(jobs);
    cout << "Example 1 Output: " << result.first << " " << result.second << endl;

    jobs = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}};
    cout << "Example 2 Input: {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}" << endl;
    result = jobScheduling(jobs);
    cout << "Example 2 Output: " << result.first << " " << result.second << endl;

    return 0;
}
