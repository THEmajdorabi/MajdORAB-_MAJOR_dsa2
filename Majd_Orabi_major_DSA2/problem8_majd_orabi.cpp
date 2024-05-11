#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(const string &s) {
    if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0') || stoi(s) > 255)
        return false;
    return true;
}

vector<string> restoreIpAddresses(const string &s) {
    vector<string> result;
    for (int a = 1; a <= 3; ++a)
    for (int b = 1; b <= 3; ++b)
    for (int c = 1; c <= 3; ++c)
    for (int d = 1; d <= 3; ++d)
        if (a + b + c + d == s.size()) {
            string part1 = s.substr(0, a);
            string part2 = s.substr(a, b);
            string part3 = s.substr(a + b, c);
            string part4 = s.substr(a + b + c, d);
            if (isValid(part1) && isValid(part2) && isValid(part3) && isValid(part4)) {
                result.push_back(part1 + "." + part2 + "." + part3 + "." + part4);
            }
        }
    return result;
}

int main() {
    string input = "25525511135";
    vector<string> ips = restoreIpAddresses(input);
    cout << "Example 1 Input: S = " << input << endl;
    if (ips.empty()) {
        cout << "Example 1 Output: -1" << endl;
    } else {
        cout << "Example 1 Output: ";
        for (const string &ip : ips) cout << ip << " ";
        cout << endl;
    }

    input = "1111";
    ips = restoreIpAddresses(input);
    cout << "Example 2 Input: S = " << input << endl;
    cout << "Example 2 Output: ";
    for (const string &ip : ips) cout << ip << " ";
    cout << endl;

    return 0;
}
