/*
 * Problem: 3534. Path Existence Queries in a Graph II
 * Link: https://leetcode.com/problems/path-existence-queries-in-a-graph-ii
 * Author: LatifY
 * Date: 10 July 2026
 * Time Complexity: O((N + Q) log N)
 * Space Complexity: O(N log N)
 */

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> ans;
        ans.reserve(queries.size());
        vector<pair<int, int>> sortedNumAndIndexes(n);
        
        for (int i = 0; i < n; ++i) {
            sortedNumAndIndexes[i] = {nums[i], i};
        }
        
        sort(sortedNumAndIndexes.begin(), sortedNumAndIndexes.end());
        
        vector<int> sortedNums(n);
        vector<int> indexMap(n);
        
        for (int i = 0; i < n; ++i) {
            sortedNums[i] = sortedNumAndIndexes[i].first;
            indexMap[sortedNumAndIndexes[i].second] = i;
        }
        
        int maxLevel = 0;
        while ((1 << maxLevel) <= n) {
            maxLevel++;
        }
        
        vector<vector<int>> jump(n, vector<int>(maxLevel));
        int right = 0;
        
        for (int i = 0; i < n; ++i) {
            while (right + 1 < n && sortedNums[right + 1] - sortedNums[i] <= maxDiff) {
                ++right;
            }
            jump[i][0] = right;
        }
        
        for (int level = 1; level < maxLevel; ++level) {
            for (int i = 0; i < n; ++i) {
                jump[i][level] = jump[jump[i][level - 1]][level - 1];
            }
        }
        
        for (const auto& query : queries) {
            int u = indexMap[query[0]];
            int v = indexMap[query[1]];
            
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            
            int left = min(u, v);
            int target = max(u, v);
            int steps = 0;
            
            for (int level = maxLevel - 1; level >= 0; --level) {
                if (jump[left][level] < target) {
                    left = jump[left][level];
                    steps += (1 << level);
                }
            }
            
            if (jump[left][0] >= target) {
                ans.push_back(steps + 1);
            } else {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};