/*
 * Problem: 1081. Smallest Subsequence of Distinct Characters
 * Link: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters
 * Author: LatifY
 * Date: 19 July 2026
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> visited(26);
        vector<int> freq(26);

        for(char c : s){
            freq[c - 'a']++;
        }

        string ans;
        for(char c : s){
            int idx = c - 'a';
            if(!visited[idx]){
                while(!ans.empty() && ans.back() > c){
                    if(freq[ans.back() - 'a'] > 0){
                        visited[ans.back() - 'a'] = false;
                        ans.pop_back();
                    }
                    else{
                        break;
                    }
                }
                visited[idx] = true;
                ans.push_back(c);
            }
            freq[idx]--;
        }

        return ans;
    }
};