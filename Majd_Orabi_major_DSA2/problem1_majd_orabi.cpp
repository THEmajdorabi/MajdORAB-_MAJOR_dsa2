#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting {
    int start;
    int end;
};

// Comparator function to sort meetings by their end time
bool compare(Meeting a, Meeting b) {
    return a.end < b.end;
}

int maxMeetings(vector<Meeting>& meetings) {
    sort(meetings.begin(), meetings.end(), compare);
    int count = 0;
    int last_end_time = 0;

    for (const auto& meeting : meetings) {
        if (meeting.start > last_end_time) {
            count++;
            last_end_time = meeting.end;
        }
    }

    return count;
}

int main() {
    vector<Meeting> meetings = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    cout << "Example 1 Input: {5 24, 39 60, 15 28, 27 40, 50 90}" << endl;
    cout << "Example 1 Output: " << maxMeetings(meetings) << endl;

    meetings = {{5, 10}, {1, 11}};
    cout << "Example 2 Input: {5 10, 1 11}" << endl;
    cout << "Example 2 Output: " << maxMeetings(meetings) << endl;

    return 0;
}
