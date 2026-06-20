/*
 * Problem: 1840. Maximum Building Height
 * Link: https://leetcode.com/problems/maximum-building-height
 * Author: LatifY
 * Date: 20 June 2026
 * Time Complexity: O(N log N)
 * Space Complexity: O(N log N)
 */

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        
        int totalRestrictions = restrictions.size();
        
        for (int i = 1; i < totalRestrictions; ++i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + restrictions[i][0] - restrictions[i - 1][0]);
        }
        
        for (int i = totalRestrictions - 2; i >= 0; --i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]);
        }
        
        int maxH = 0;
        
        for (int i = 1; i < totalRestrictions; ++i) {
            int heightDiff = abs(restrictions[i][1] - restrictions[i - 1][1]);
            int idDiff = restrictions[i][0] - restrictions[i - 1][0];
            int currentPeak = max(restrictions[i][1], restrictions[i - 1][1]) + (idDiff - heightDiff) / 2;
            maxH = max(maxH, currentPeak);
        }
        
        maxH = max(maxH, restrictions[totalRestrictions - 1][1] + n - restrictions[totalRestrictions - 1][0]);
        
        return maxH;
    }
};
