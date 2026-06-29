/*
 * Problem: 1967. Number of Strings That Appear as Substrings in Word
 * Link: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word
 * Author: LatifY
 * Date: 29 June 2026
 * Time Complexity: O(N x M x K)
 * Space Complexity: O(N x M x K))
 */

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size(), wordSize = word.size();
        int ans = 0;

        // maybe optimization for later
        // unordered_map<string, int> freq; 
        // for(int i = 0; i < n; i++){
        //     freq[patterns[i]]++;
        // }

        for(int k = 0; k < n; k++){
            string pattern = patterns[k];
            int patternSize = pattern.size();

            for(int i = 0; i + patternSize <= wordSize; i++){
                bool found = true;
                for(int j = 0; j < patternSize; j++){
                    if(pattern[j] != word[j + i]) {
                        found = false;
                        break;
                    }
                }
                if(found){
                    ans += 1;
                    break;
                }
            }
        }
        return ans;
    }
};