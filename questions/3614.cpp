/*
 * Problem: 3614. Process String with Special Operations II
 * Link: https://leetcode.com/problems/process-string-with-special-operations-ii
 * Author: LatifY
 * Date: 17 June 2026
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> lenAtStep(n);
        long long curLen = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                curLen++;
            } else if (s[i] == '*') {
                if (curLen > 0) {
                    curLen--;
                }
            } else if (s[i] == '#') {
                curLen *= 2;
            }
            lenAtStep[i] = curLen;
        }
        
        if (k >= lenAtStep[n - 1]) {
            return '.';
        }
        
        string tibrelkano = s;
        long long targetIdx = k;
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                if (targetIdx == lenAtStep[i] - 1) {
                    return s[i];
                }
            } else if (s[i] == '#') {
                long long prevLen = (i == 0) ? 0 : lenAtStep[i - 1];
                if (prevLen > 0 && targetIdx >= prevLen) {
                    targetIdx %= prevLen;
                }
            } else if (s[i] == '%') {
                long long prevLen = (i == 0) ? 0 : lenAtStep[i - 1];
                if (prevLen > 0) {
                    targetIdx = prevLen - 1 - targetIdx;
                }
            }
        }
        
        return '.';
    }
};