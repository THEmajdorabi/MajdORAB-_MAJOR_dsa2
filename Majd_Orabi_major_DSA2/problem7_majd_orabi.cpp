#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int node, vector<int>& colors, vector<vector<int>>& graph, int color) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[node][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, vector<int>& colors, int m, int v) {
    if (v == graph.size()) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, colors, graph, c)) {
            colors[v] = c;
            if (graphColoringUtil(graph, colors, m, v + 1)) return true;
            colors[v] = 0;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> graph = {{0, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 0}};
    int m = 3; 
    vector<int> colors(4, 0);

    cout << "Example 1 Input: N = 4, M = 3, E = 5, Edges[] = {(0,1), (1,2), (2,3), (3,0), (0,2)}" << endl;
    cout << "Example 1 Output: " << (graphColoringUtil(graph, colors, m, 0) ? 1 : 0) << endl;

    return 0;
}
