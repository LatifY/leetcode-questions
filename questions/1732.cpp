/*
 * Problem: 1732. Find the Highest Altitude
 * Link: https://leetcode.com/problems/find-the-highest-altitude
 * Author: LatifY
 * Date: 19 June 2026
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0, maxAlt = 0;
        for(int i = 0; i < gain.size(); i++){
            alt += gain[i];
            maxAlt = max(maxAlt, alt);
        }
        
        return maxAlt;
    }
};