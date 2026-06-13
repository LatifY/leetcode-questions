/*
 * Problem: 3838. Weighted Word Mapping
 * Link: https://leetcode.com/problems/weighted-word-mapping
 * Author: LatifY
 * Date: 13 June 2026
 * Time Complexity: O(N x L)
 * Space Complexity: O(1)
 */

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;
        for(string w : words){
            int totalWeight = 0;
            for(char c : w){
                totalWeight += weights[c - 'a'];
            }
            res += 'a' + (25 - totalWeight % 26);
        }
        return res;
    }
};

