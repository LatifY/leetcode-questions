/*
 * Problem: 1189. Maximum Number of Balloons
 * Link: https://leetcode.com/problems/maximum-number-of-balloons
 * Author: LatifY
 * Date: 22 June 2026
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count(5, 0); // b a l o n
        int n = text.size();

        for(int i = 0; i < n; i++){
            char c = text[i];
            if(c == 'b') count[0]++;
            else if(c == 'a') count[1]++;
            else if(c == 'l') count[2]++;
            else if(c == 'o') count[3]++;
            else if(c == 'n') count[4]++;
        }
        count[2] /= 2;
        count[3] /= 2;

        int ans = *min_element(count.begin(), count.end());
        return ans;
    }
};