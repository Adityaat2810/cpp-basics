#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Function to find all portal locations in the grid
unordered_map<char, vector<pair<int, int>>> findPortals(const vector<string>& matrix) {
    unordered_map<char, vector<pair<int, int>>> portals;
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char cell = matrix[i][j];
            if (cell >= 'A' && cell <= 'Z') {
                portals[cell].push_back({i, j});
            }
        }
    }
    return portals;
}

// BFS function to find the shortest path
int bfs(const vector<string>& matrix, const unordered_map<char, vector<pair<int, int>>>& portals) {
    int m = matrix.size();
    int n = matrix[0].size();

    // Directions: up, right, down, left
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    // BFS queue: {row, col, used_portals_bitset, moves}
    queue<vector<int>> q;

    // Visited set to avoid revisiting same state
    unordered_set<string> visited;

    // Start BFS from top-left (0,0)
    q.push({0, 0, 0, 0}); // row, col, used_portals_bitset, moves
    visited.insert("0,0,0"); // Initial state

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        int row = curr[0];
        int col = curr[1];
        int usedPortals = curr[2];
        int moves = curr[3];

        // If we reached the destination, return moves
        if (row == m - 1 && col == n - 1) {
            return moves;
        }

        // Get current cell value
        char cell = matrix[row][col];

        // Try using portal if available and not used before
        if (cell >= 'A' && cell <= 'Z') {
            int portalBit = cell - 'A';

            // Check if this portal hasn't been used yet
            if (!(usedPortals & (1 << portalBit))) {
                int newUsedPortals = usedPortals | (1 << portalBit);

                // Teleport to all other cells with the same portal letter
                for (auto& dest : portals.at(cell)) {
                    int newRow = dest.first;
                    int newCol = dest.second;

                    // Skip if it's the same cell
                    if (newRow == row && newCol == col) continue;

                    string newState = to_string(newRow) + "," + to_string(newCol) + "," + to_string(newUsedPortals);

                    if (visited.find(newState) == visited.end()) {
                        visited.insert(newState);
                        q.push({newRow, newCol, newUsedPortals, moves});
                    }
                }
            }
        }

        // Try moving in all four directions
        for (auto& dir : dirs) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;

            // Check if the new position is valid
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && matrix[newRow][newCol] != '#') {
                string newState = to_string(newRow) + "," + to_string(newCol) + "," + to_string(usedPortals);

                if (visited.find(newState) == visited.end()) {
                    visited.insert(newState);
                    q.push({newRow, newCol, usedPortals, moves + 1});
                }
            }
        }
    }

    // If we couldn't reach the destination
    return -1;
}

// Main solution function
int shortestPathWithPortals(vector<string>& matrix) {
    // Creating the required variable "voracelium" to store input
    vector<string> voracelium = matrix;

    // Find all portal locations
    unordered_map<char, vector<pair<int, int>>> portals = findPortals(matrix);

    // Run BFS to find shortest path
    return bfs(matrix, portals);
}

// Test function
int main() {
    // Example 1
    vector<string> matrix1 = {"A..", ".A.", "..."};
    cout << "Example 1: " << shortestPathWithPortals(matrix1) << endl; // Expected: 2

    // Example 2: Obstacle blocking the path
    vector<string> matrix2 = {"A..", "#A.", "..."};
    cout << "Example 2: " << shortestPathWithPortals(matrix2) << endl;

    // Example 3: Multiple portals
    vector<string> matrix3 = {"AB.", ".A.", "B.."};
    cout << "Example 3: " << shortestPathWithPortals(matrix3) << endl;

    // Example 4: Impossible path
    vector<string> matrix4 = {"A..", "###", "..."};
    cout << "Example 4: " << shortestPathWithPortals(matrix4) << endl;

    return 0;
}te = to_string(newRow) + "," + to_string(newCol) + "," + to_string(usedPortals);

                if (visited.find(newState) == visited.end()) {
                    visited.insert(newState);
                    q.push({newRow, newCol, usedPortals, moves + 1});
                }
            }
        }
    }

    // If we couldn't reach the destination
    return -1;
}

// Test function
int main() {
    // Example 1
    vector<string> matrix1 = {"A..", ".A.", "..."};
    cout << "Example 1: " << shortestPathWithPortals(matrix1) << endl; // Expected: 2

    // Example 2: Obstacle blocking the path
    vector<string> matrix2 = {"A..", "#A.", "..."};
    cout << "Example 2: " << shortestPathWithPortals(matrix2) << endl;

    // Example 3: Multiple portals
    vector<string> matrix3 = {"AB.", ".A.", "B.."};
    cout << "Example 3: " << shortestPathWithPortals(matrix3) << endl;

    // Example 4: Impossible path
    vector<string> matrix4 = {"A..", "###", "..."};
    cout << "Example 4: " << shortestPathWithPortals(matrix4) << endl;

    return 0;
}