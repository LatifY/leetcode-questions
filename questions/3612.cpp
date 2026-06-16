/*
 * Problem: 3612. Process String with Special Operations I
 * Link: https://leetcode.com/problems/process-string-with-special-operations-i
 * Author: LatifY
 * Date: 16 June 2026
 * Time Complexity: O(2^N)
 * Space Complexity: O(2^N)
 */

class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(char c : s){
            if(c >= 'a' && c <= 'z') res += c;
            else if(c == '*'){
                if(res.size() > 0) res.pop_back();
            }
            else if(c == '#') res += res;
            else if(c == '%') reverse(res.begin(), res.end());
        }

        return res;
    }
};

