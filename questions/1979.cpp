/*
 * Problem: 1979. Find Greatest Common Divisor of Array
 * Link: https://leetcode.com/problems/find-greatest-common-divisor-of-array
 * Author: LatifY
 * Date: 18 July 2026
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int findGCD(vector<int>& nums) {
        return gcd(*max_element(nums.begin(), nums.end()), *min_element(nums.begin(), nums.end()));
    }
};