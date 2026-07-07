/*
 * Problem: 3754. Concatenate Non-Zero Digits and Multiply by Sum I
 * Link: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i
 * Author: LatifY
 * Date: 07 July 2026
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0, sum = 0;
        int i = 0;
        while(n > 0){
            int d = n % 10;
            n = (n - d) / 10;
            if(d == 0) continue;
            num = num + pow(10, i) * d;
            sum += d;

            i++;
        }
        return num * sum;
    }
};