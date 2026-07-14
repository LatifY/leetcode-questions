/*
 * Problem: 3336. Find the Number of Subsequences With Equal GCD
 * Link: https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd
 * Author: LatifY
 * Date: 14 July 2026
 * Time Complexity: O(n x m^2 x log m)
 * Space Complexity: O(m^2)
 */

class Solution {
public:
    void printMat(vector<vector<int>>& arr, int n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout <<  setw(3) << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int subsequencePairCount(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        long long mod = 1e9 + 7;

        vector<vector<int>> dp(m + 1, vector<int>(m + 1));
        dp[0][0] = 1;

        for(int num : nums){
            vector<vector<int>> tempDp(m + 1, vector<int>(m + 1));

            for(int i = 0; i < m + 1; i++){
                int seq1 = gcd(i, num);
                for(int j = 0; j < m + 1; j++){
                    int val = dp[i][j];
                    if (val == 0) continue;
                    int seq2 = gcd(j, num);
                    tempDp[i][j] = (tempDp[i][j] + val) % mod;
                    tempDp[seq1][j] = (tempDp[seq1][j] + val) % mod;
                    tempDp[i][seq2] = (tempDp[i][seq2] + val) % mod;
                }
            }
            dp.swap(tempDp);
            printMat(dp, m + 1);
        }


        int ans = 0;
        for(int i = 1; i < m + 1; i++){
            ans = (ans + dp[i][i]) % mod;
        }

        return ans;
    }
};