/*
 * Problem: 1331. Rank Transform of an Array
 * Link: https://leetcode.com/problems/rank-transform-of-an-array
 * Author: LatifY
 * Date: 12 July 2026
 * Time Complexity: O(N log N)
 * Space Complexity: O(N)
 */

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> tmp = arr;
        vector<int> ans(n);

        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        int tmpSize = tmp.size();

        unordered_map<int, int> rankMap;
        for(int i = 0; i < tmpSize; i++){
            rankMap[tmp[i]] = i + 1;
        }

        for(int i = 0; i < n; i++){
            ans[i] = rankMap[arr[i]];
        }

        return ans;
    }
};