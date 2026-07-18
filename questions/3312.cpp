/*
 * Problem: 3312. Sorted GCD Pair Queries
 * Link: https://leetcode.com/problems/sorted-gcd-pair-queries
 * Author: LatifY
 * Date: 17 July 2026
 * Time Complexity: O(N + M log M + Q log M)
 * Space Complexity: O(M + Q)
 */

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = *max_element(nums.begin(), nums.end());
        
        vector<int> freq(max_val + 1, 0);
        for (int x : nums) {
            freq[x]++;
        }
        
        vector<long long> cnt_multiples(max_val + 1, 0);
        for (int i = 1; i <= max_val; i++) {
            long long count = 0;
            for (int j = i; j <= max_val; j += i) {
                count += freq[j];
            }
            cnt_multiples[i] = count;
        }
        
        vector<long long> exact_gcd(max_val + 1, 0);
        for (int i = max_val; i >= 1; i--) {
            long long pairs = cnt_multiples[i] * (cnt_multiples[i] - 1) / 2;
            
            for (int j = 2 * i; j <= max_val; j += i) {
                pairs -= exact_gcd[j];
            }
            exact_gcd[i] = pairs;
        }
        
        vector<long long> pref(max_val + 1, 0);
        for (int i = 1; i <= max_val; i++) {
            pref[i] = pref[i - 1] + exact_gcd[i];
        }
        
        vector<int> ans;
        for (long long q : queries) {
            int l = 1, r = max_val, res = 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (pref[mid] > q) {
                    res = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            ans.push_back(res);
        }
        
        return ans;
    }
};