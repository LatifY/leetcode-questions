/*
 * Problem: 3020. Find the Maximum Number of Elements in Subset
 * Link: https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset
 * Author: LatifY
 * Date: 27 June 2026
 * Time Complexity: O(N log M)
 * Space Complexity: O(N log M)
 */

class Solution {

public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        int onesCount = count(nums.begin(), nums.end(), 1);
        ans = onesCount % 2 == 1 ? onesCount : onesCount - 1;
        ans = onesCount == 0 ? 0 : ans; //these two are probably the shittiest lines i wrote in my entire life

        unordered_map<long long, int> freq;
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        }

        for(auto const& [num, count] : freq){
            if(num <= 1) continue;

            int currLen = 0;
            long long curr = num;

            while(freq.count(curr) && freq[curr] >= 2){
                currLen += 2;
                curr *= curr;
            }

            if(freq.count(curr) && freq[curr] == 1) currLen += 1;
            else currLen -= 1;

            ans = max(ans, currLen);
        }

        return ans;
    }
};