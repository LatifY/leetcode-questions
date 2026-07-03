/*
 * Problem: 3620. Network Recovery Pathways
 * Link: https://leetcode.com/problems/network-recovery-pathways
 * Author: LatifY
 * Date: 3 July 2026
 * Time Complexity: O(M log M log N)
 * Space Complexity: O(M + N)
 */

class Solution {

public:
    bool check(int mid, int n, const vector<vector<pair<int, int>>>& adj, long long k) {
        vector<long long> best(n, 1e18);
        best[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});

        while(!pq.empty()){
            auto [current_cost, node] = pq.top();
            pq.pop();

            if(current_cost > best[node]) continue;
            if(node == n - 1) return current_cost <= k;

            for(auto& edge : adj[node]){
                int next_node = edge.first;
                long long edge_cost = edge.second;

                if(edge_cost < mid) continue;

                long long next_cost = current_cost + edge_cost;
                if(next_cost < best[next_node]){
                    best[next_node] = next_cost;
                    pq.push({next_cost, next_node});
                }
            }
        }
        return best[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int, int>>> adj(n);
        for(const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            if(!online[u] || !online[v]) continue;

            adj[u].push_back({v, cost});

            //adj[v].push_back({u, cost}); undirected graph
        }

        int left = 0;
        int right = 1e9;
        int ans = -1;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            
            if(check(mid, n, adj, k)){
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};