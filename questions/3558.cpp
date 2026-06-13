/*
 * Problem: 3558. Number of Ways to Assign Edge Weights I
 * Link: https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i
 * Author: LatifY
 * Date: 11 June 2026
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

class Solution {
public:
    void dfs(int node, int currDepth, int& maxDepth, vector<bool>& visited, vector<vector<int>>& adj){
        visited[node] = true;
        maxDepth = max(maxDepth, currDepth);

        for(int n : adj[node]) {
            if(!visited[n]){
                dfs(n, currDepth + 1, maxDepth,
                 visited, adj);
            }
        }

        visited[node] = false;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int maxDepth = 0, maxNode = 0;
        long long ans = 1;
        long long mod = 1e9 + 7;

        for (const auto& edge : edges) {
            maxNode = max(maxNode, edge[0]);
            maxNode = max(maxNode, edge[1]);
        }

        vector<vector<int>> adj(maxNode + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(maxNode + 1, false);
        dfs(1, 0, maxDepth, visited, adj);
        for(int i = 0; i < maxDepth - 1; i++) ans = (ans << 1) % mod;
        return ans;
    }
};