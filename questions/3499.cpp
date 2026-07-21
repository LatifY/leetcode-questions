/*
 * Problem: 3499. Maximize Active Section with Trade I
 * Link: https://leetcode.com/problems/maximize-active-section-with-trade-i
 * Author: LatifY
 * Date: 21 July 2026
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

class Solution {
public:
    // max(sum of zero segments in contigious blocks) + 1's in original string
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<int> zeroSegments;
        int counter = 0, onesCounter = 0;
        
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                onesCounter++;
                if(counter > 0)
                {
                    zeroSegments.push_back(counter);
                    counter = 0;
                }
                continue;
            }
            counter++;
        }
        if(counter > 0) zeroSegments.push_back(counter);

        int maxZeros = 0;
        for(int i = 1; i < zeroSegments.size(); i++){
            maxZeros = max(maxZeros, zeroSegments[i] + zeroSegments[i - 1]);
        }

        return maxZeros + onesCounter;
    }
};