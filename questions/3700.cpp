/*
 * Problem: 3700. Number of ZigZag Arrays II
 * Link: https://leetcode.com/problems/number-of-zigzag-arrays-ii
 * Author: LatifY
 * Date: 24 June 2026
 * Time Complexity: O(m^3 log n)
 * Space Complexity: O(m^3 log n)
 */

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        long long mod = 1e9 + 7;
        int m = r - l + 1;

        if (n == 1) return m;

        int size = 2 * m;
        vector<vector<long long>> T(size, vector<long long>(size, 0));

        for (int v = 0; v < m; v++) {
            for (int k = v + 1; k < m; k++) {
                T[v][m + k] = 1;
            }

            for (int k = 0; k < v; k++) {
                T[m + v][k] = 1;
            }
        }

        auto multiply = [&](const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
            vector<vector<long long>> C(size, vector<long long>(size, 0));
            for (int i = 0; i < size; i++) {
                for (int k = 0; k < size; k++) {
                    if (A[i][k] == 0) continue;
                    for (int j = 0; j < size; j++) {
                        C[i][j] += A[i][k] * B[k][j];
                        // 8e18 safely smaller than signed 64-bit integer
                        if (C[i][j] >= 8000000000000000000LL) {
                            C[i][j] %= mod;
                        }
                    }
                }
                for (int j = 0; j < size; j++) {
                    C[i][j] %= mod;
                }
            }
            return C;
        };

        auto power = [&](vector<vector<long long>> A, long long p) {
            vector<vector<long long>> res(size, vector<long long>(size, 0));
            for (int i = 0; i < size; i++) res[i][i] = 1; // identity matrix

            while (p > 0) {
                if (p % 2 == 1) res = multiply(res, A);
                A = multiply(A, A);
                p /= 2;
            }
            return res;
        };

        vector<vector<long long>> Tn = power(T, n - 1);

        long long ans = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                ans = (ans + Tn[i][j]) % mod;
            }
        }

        return ans;
    }
};