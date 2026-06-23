/*
 * Problem: 3699. Number of ZigZag Arrays I
 * Link: https://leetcode.com/problems/number-of-zigzag-arrays-i
 * Author: LatifY
 * Date: 23 June 2026
 * Time Complexity: O(n x m)
 * Space Complexity: O(n x m)
 */

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        long long mod = 1e9 + 7;
        int m = r - l + 1;

        if (n == 1) return m;

        vector<vector<long long>> prevDp(m, vector<long long>(2, 1));
        vector<vector<long long>> currDp(m, vector<long long>(2, 0));
        vector<long long> pre(m, 0);
        vector<long long> suff(m, 0);

        for (int i = 1; i < n; i++) {
            long long prefixSum = 0;
            for (int v = 0; v < m; v++) {
                prefixSum += prevDp[v][0];
                if (prefixSum >= mod) prefixSum -= mod;
                pre[v] = prefixSum;
            }

            long long suffixSum = 0;
            for (int v = m - 1; v >= 0; v--) {
                suffixSum += prevDp[v][1];
                if (suffixSum >= mod) suffixSum -= mod;
                suff[v] = suffixSum;
            }

            for (int v = 0; v < m; v++) {
                if (v < m - 1) currDp[v][0] = suff[v + 1];
                else currDp[v][0] = 0;

                if (v > 0) currDp[v][1] = pre[v - 1];
                else currDp[v][1] = 0;
            }

            swap(prevDp, currDp);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans += prevDp[i][0];
            if (ans >= mod) ans -= mod;
            ans += prevDp[i][1];
            if (ans >= mod) ans -= mod;
        }

        return ans;
    }
};