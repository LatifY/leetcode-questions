/*
 * Problem: 3532. Path Existence Queries in a Graph I
 * Link: https://leetcode.com/problems/path-existence-queries-in-a-graph-i
 * Author: LatifY
 * Date: 9 July 2026
 * Time Complexity: O(N + M)
 * Space Complexity: O(N)
 */

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> g(n, 0);
        int counter = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                counter++;
            }
            g[i] = counter;
        }
        
        int m = queries.size();
        vector<bool> ans(m);
        for (int i = 0; i < m; i++) {
            ans[i] = g[queries[i][0]] == g[queries[i][1]];
        }
        
        return ans;
    }
};