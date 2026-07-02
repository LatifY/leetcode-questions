/*
 * Problem: 3286. Find a Safe Walk Through a Grid
 * Link: https://leetcode.com/problems/find-a-safe-walk-through-a-grid
 * Author: LatifY
 * Date: 02 July 2026
 * Time Complexity: O(M * N log(M * N))
 * Space Complexity: O(M * N)
 */

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        if(health == 1 && grid[0][0] == 1) return false;

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({health - grid[0][0], {0, 0}});

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int currHealth = health;

        while(!pq.empty()){
            auto [h, pos] = pq.top();
            pq.pop();

            int r = pos.first, c = pos.second;
            // if(r < 0 || r > m || c < 0 || c > n || h <= 0) continue;
            
            if(r == m - 1 && c == n - 1) return h > 0;

            for(const auto& [x, y] : dirs){
                int nr = r + x;
                int nc = c + y;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]){
                    visited[nr][nc] = true;
                    pq.push({h - grid[nr][nc], {nr, nc}});
                }
            }
        }
        return false;
    }
};