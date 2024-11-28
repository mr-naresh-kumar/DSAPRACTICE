#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    #define P pair<int, pair<int, int>>
    
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Directions for moving in 4 possible ways (up, down, left, right)
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Result matrix to store the minimum obstacle count
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        result[0][0] = 0;

        // Min-heap priority queue to explore minimum obstacle path first
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});  // {weight, {i, j}}

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int d = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            // Explore all 4 possible directions
            for (auto& dir : directions) {
                int x = i + dir[0];
                int y = j + dir[1];

                // Boundary check
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }

                // Weight for the next cell
                int wt = (grid[x][y] == 1) ? 1 : 0;
//   cout<< "Naresh" << endl;

                // Relaxation step: update result[x][y] if a shorter path is found
                if (d + wt < result[x][y]) {
                    result[x][y] = d + wt;
                    pq.push({d + wt, {x, y}});
                }
            }
        }

        return result[m - 1][n - 1];
    }
};



int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0, 1, 1},
        {1, 1, 0},
        {1, 1, 0}
    };
    int result = sol.minimumObstacles(grid);
    // Expected Output: 2
    return 0;
}
