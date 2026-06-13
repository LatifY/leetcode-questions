/*
 * Problem: 3559. Number of Ways to Assign Edge Weights II
 * Link: https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-ii
 * Author: LatifY
 * Date: 12 June 2026
 * Time Complexity: O(N log N)
 * Space Complexity: O(N)
 */

#define LOG 20

class Solution {
public:
    vector<vector<int>> up;

    void dfs(int node, int currDepth, int parent, vector<int>& depths, vector<vector<int>>& adj) {
        depths[node] = currDepth;
        up[node][0] = parent;

        for(int i = 1; i < LOG; i++){
            up[node][i] = up[up[node][i - 1]][i - 1];
        }

        for(int n : adj[node]) {
            if(n != parent){
                dfs(n, currDepth + 1, node, depths, adj);
            }
        }
    }

    int getLCA(int u, int v, vector<int>& depths, vector<vector<int>>& up){
        if(depths[u] < depths[v]) swap(u, v);
        int diff = depths[u] - depths[v];
        for(int i = 31; i >= 0; i--){
            if((diff >> i) & 1){
                u = up[u][i];
                if (u == v) return u;
            }
        }

        if (u == v) return u;

        for(int i = LOG - 1; i >= 0; i--){
            if(up[u][i] != up[v][i]){
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int maxNode = 0;

        for(const auto& edge : edges){
            maxNode = max(maxNode, edge[0]);
            maxNode = max(maxNode, edge[1]);
        }

        vector<vector<int>> adj(maxNode + 1);
        for(const auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(maxNode + 1, false);
        vector<int> depths(maxNode + 1);
        up.assign(maxNode + 1, vector<int>(LOG, 0));
        dfs(1, 0, 1, depths, adj);

        vector<int> ans;
        long long mod = 1e9 + 7;
        vector<int> pow2(maxNode + 1, 1);
        for(int i = 1; i <= maxNode; i++){
            pow2[i] = (pow2[i - 1] << 1) % mod;
        }

        for(const auto& q : queries){
            int lca = 0;
            lca = getLCA(q[0],q[1], depths, up);

            int n = 1;
            int len = depths[q[0]] + depths[q[1]] - (2 * depths[lca]);
            if (len == 0) {
                ans.push_back(0);
            } else {
                ans.push_back(pow2[len - 1]);
            }
        }

        return ans;
    }
};