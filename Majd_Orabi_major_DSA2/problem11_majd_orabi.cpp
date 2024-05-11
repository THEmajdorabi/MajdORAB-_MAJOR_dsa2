#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool canAllocate(const vector<int>& books, int students, int maxPages) {
    int count = 1;
    int total = 0;

    for (int pages : books) {
        if (total + pages > maxPages) {
            total = pages;
            count++;
            if (count > students) {
                return false;
            }
        } else {
            total += pages;
        }
    }
    return true;
}

int findPages(const vector<int>& books, int students) {
    if (students > books.size()) {
        return -1;
    }
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canAllocate(books, students, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    vector<int> books = {12, 34, 67, 90};
    int students = 2;
    cout << "Example 1 Input: N = 4, A[] = {12, 34, 67, 90}, M = 2" << endl;
    cout << "Example 1 Output: " << findPages(books, students) << endl;

    books = {15, 17, 20};
    students = 2;
    cout << "Example 2 Input: N = 3, A[] = {15, 17, 20}, M = 2" << endl;
    cout << "Example 2 Output: " << findPages(books, students) << endl;

    return 0;
}
