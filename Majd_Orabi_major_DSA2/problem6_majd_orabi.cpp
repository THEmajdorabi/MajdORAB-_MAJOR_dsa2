#include <iostream>
#include <vector>
#include <string>

using namespace std;

void findPathsUtil(vector<vector<int>>& maze, int x, int y, string path, vector<string>& paths, vector<vector<bool>>& visited) {
    int n = maze.size();
    if (x < 0 || x >= n || y < 0 || y >= n || maze[x][y] == 0 || visited[x][y]) return;

    if (x == n - 1 && y == n - 1) {
        paths.push_back(path);
        return;
    }

    visited[x][y] = true;
    if (x > 0) findPathsUtil(maze, x - 1, y, path + 'U', paths, visited);
    if (y > 0) findPathsUtil(maze, x, y - 1, path + 'L', paths, visited);
    if (x < n - 1) findPathsUtil(maze, x + 1, y, path + 'D', paths, visited);
    if (y < n - 1) findPathsUtil(maze, x, y + 1, path + 'R', paths, visited);
    visited[x][y] = false;
}

int main() {
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> paths;
    vector<vector<bool>> visited(4, vector<bool>(4, false));

    findPathsUtil(maze, 0, 0, "", paths, visited);

    cout << "Example 1 Input: N = 4, m[][] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}}" << endl;
    if (paths.empty()) {
        cout << "Example 1 Output: -1" << endl;
    } else {
        cout << "Example 1 Output: ";
        for (const auto& path : paths) cout << path << " ";
        cout << endl;
    }

    return 0;
}
