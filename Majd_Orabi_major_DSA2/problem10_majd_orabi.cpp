#include <iostream>
#include <vector>

using namespace std;

int findKth(const vector<int>& nums1, const vector<int>& nums2, int k) {
    int m = nums1.size(), n = nums2.size();
    int i = 0, j = 0;

    while (true) {
        if (i == m) {
            return nums2[j + k - 1];
        }
        if (j == n) {
            return nums1[i + k - 1];
        }
        if (k == 1) {
            return min(nums1[i], nums2[j]);
        }

        int mid1 = (i + k / 2 - 1 < m) ? nums1[i + k / 2 - 1] : INT_MAX;
        int mid2 = (j + k / 2 - 1 < n) ? nums2[j + k / 2 - 1] : INT_MAX;

        if (mid1 < mid2) {
            i += k / 2;
        } else {
            j += k / 2;
        }
        k -= k / 2;
    }
}

int main() {
    vector<int> nums1 = {2, 3, 6, 7, 9};
    vector<int> nums2 = {1, 4, 8, 10};
    int k = 5;
    cout << "Example 1 Input: arr1[] = {2, 3, 6, 7, 9}, arr2[] = {1, 4, 8, 10}, k = 5" << endl;
    cout << "Example 1 Output: " << findKth(nums1, nums2, k) << endl;

    nums1 = {100, 112, 256, 349, 770};
    nums2 = {72, 86, 113, 119, 265, 445, 892};
    k = 7;
    cout << "Example 2 Input: arr1[] = {100, 112, 256, 349, 770}, arr2[] = {72, 86, 113, 119, 265, 445, 892}, k = 7" << endl;
    cout << "Example 2 Output: " << findKth(nums1, nums2, k) << endl;

    return 0;
}
