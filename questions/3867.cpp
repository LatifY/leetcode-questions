/*
 * Problem: 3867. Sum of GCD of Formed Pairs
 * Link: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs
 * Author: LatifY
 * Date: 16 July 2026
 * Time Complexity: O(N log N)
 * Space Complexity: O(N)
 */

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        vector<int> prefixGcd(n, 0);

        for(int i = 0; i < n; i++){
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }

        sort(prefixGcd.begin(), prefixGcd.end());
        long long ans = 0;

        for(int i = 0; i < n / 2; i++){
            ans += gcd(prefixGcd[i], prefixGcd[n - i - 1]);
        }

        return ans;
    }
};