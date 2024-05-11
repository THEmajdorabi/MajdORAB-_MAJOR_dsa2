#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>  

using namespace std;

struct Position {
    int x, y;
};

const vector<Position> directions = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
};

void findWordsUtil(const vector<vector<char>>& board, int i, int j, string& current, const vector<string>& dict, vector<vector<bool>>& visited, unordered_set<string>& found) {
    if (current.length() > 10) return;  

    if (find(dict.begin(), dict.end(), current) != dict.end()) {
        found.insert(current);
    }

    visited[i][j] = true;

    for (const auto& dir : directions) {
        int new_i = i + dir.x, new_j = j + dir.y;
        if (new_i >= 0 && new_i < board.size() && new_j >= 0 && new_j < board[0].size() && !visited[new_i][new_j]) {
            current.push_back(board[new_i][new_j]);
            findWordsUtil(board, new_i, new_j, current, dict, visited, found);
            current.pop_back();
        }
    }

    visited[i][j] = false;
}

unordered_set<string> findWords(vector<vector<char>>& board, const vector<string>& dict) {
    unordered_set<string> found;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    string current;

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            current.push_back(board[i][j]);
            findWordsUtil(board, i, j, current, dict, visited, found);
            current.pop_back();
        }
    }

    return found;
}

int main() {
    vector<vector<char>> board = {{'G', 'I', 'Z'}, {'U', 'E', 'K'}, {'Q', 'S', 'E'}};
    vector<string> dictionary = {"GEEKS", "FOR", "QUIZ", "GO"};
    unordered_set<string> words = findWords(board, dictionary);

    cout << "Example 1 Input: Dictionary = {\"GEEKS\", \"FOR\", \"QUIZ\", \"GO\"}, Board = {{'G', 'I', 'Z'}, {'U', 'E', 'K'}, {'Q', 'S', 'E'}}" << endl;
    cout << "Example 1 Output: ";
    for (const string& word : words) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
