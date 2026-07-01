/*
 * Problem: 2812. Find the Safest Path in a Grid
 * Link: https://leetcode.com/problems/find-the-safest-path-in-a-grid
 * Author: LatifY
 * Date: 1 July 2026
 * Time Complexity: O(N^2 log N)
 * Space Complexity: O(N^2 log N)
 */


class Solution {
public:
struct Point {
        int r, c;
        
        bool operator<(const Point& other) const {
            if (r != other.r) return r < other.r;
            return c < other.c;
        }
    };

    typedef pair<int, Point> PQPair;

    void printMat(vector<vector<int>>& grid, int n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }


    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;

        queue<Point> q;
        vector<vector<int>> dist(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] ==  1)
                {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        // printMat(dist, n);

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < dirs.size(); i++){
                int nr = r + dirs[i].first;
                int nc = c + dirs[i].second;

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1){
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // printMat(dist, n);

        priority_queue<PQPair> pq;
        pq.push({dist[0][0], {0, 0}});

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        while (!pq.empty()) {
            auto [safeness, pos] = pq.top();
            pq.pop();

            int r = pos.r, c = pos.c;

            if(r == n - 1 && c == n - 1) return safeness;

            for(int i = 0; i < dirs.size(); i++){
                int nr = r + dirs[i].first;
                int nc = c + dirs[i].second;

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]){
                    visited[nr][nc] = true;
                    int pathSafeness = min(safeness, dist[nr][nc]);
                    pq.push({pathSafeness, {nr, nc}});
                }
            }
        }
        return 0;
    }
};