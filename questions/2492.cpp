/*
 * Problem: 2492. Minimum Score of a Path Between Two Cities
 * Link: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities
 * Author: LatifY
 * Date: 04 July 2026
 * Time Complexity: O(N + E)
 * Space Complexity: O(N + E)
 */

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for(auto& road : roads){
            int a = road[0];
            int b = road[1];
            int distance = road[2];

            adj[a].push_back({b, distance});
            adj[b].push_back({a, distance});
        }

        //bfs
        queue<int> q;
        vector<bool> visited(n+1, false);
        int ans = INT_MAX;

        q.push(1);
        visited[1] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(auto& edge : adj[curr]){
                int neighbour = edge.first;
                int distance = edge.second;

                ans = min(ans, distance);

                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        return ans;
    }
};