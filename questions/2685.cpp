/*
 * Problem: 2685. Count the Number of Complete Components
 * Link: https://leetcode.com/problems/count-the-number-of-complete-components
 * Author: LatifY
 * Date: 11 July 2026
 * Time Complexity: O(V + E)
 * Space Complexity: O(V + E)
 */

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& edge : edges){
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int ans = 0;
        vector<int> visited(n, false);

        for(int i = 0; i < n; i++){
            if(visited[i]) continue;

            queue<int> q;
            q.push(i);
            visited[i] = true;

            int edgeCountTotal = 0; //this is bidirectional
            int verticeCount = 0;

            while(!q.empty()){
                int curr = q.front();
                q.pop();

                verticeCount++;
                edgeCountTotal += adj[curr].size();

                for(auto& ne : adj[curr]){
                    if(visited[ne]) continue;
                    visited[ne] = true;
                    q.push(ne);
                }
            }

            if(edgeCountTotal == verticeCount * (verticeCount - 1)) ans++;
        }
         
        return ans;
    }

};