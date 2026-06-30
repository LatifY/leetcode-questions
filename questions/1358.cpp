/*
 * Problem: 1358. Number of Substrings Containing All Three Characters
 * Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters
 * Author: LatifY
 * Date: 30 June 2026
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

class Solution {
public:
    bool checkFreq(int freq[]){
        return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
    }

    int numberOfSubstrings(string s) {
        int len = s.size(), left = 0, right = 0, ans = 0;

        int freq[3] = {0, 0, 0};

        while(right < len){
            char c = s[right];
            freq[c - 'a']++;

            while(checkFreq(freq)){
                ans += len - right;
                freq[s[left++] - 'a']--;
            }
            right++;
        }

        return ans;
    }
};