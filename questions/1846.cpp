/*
 * Problem: 1846. Maximum Element After Decreasing and Rearranging
 * Link: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging
 * Author: LatifY
 * Date: 28 June 2026
 * Time Complexity: O(N log N)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size(), ans = 1;
        sort(arr.begin(), arr.end());
        arr[0] = 1;

        for(int i = 1; i < n; i++){
            int num = arr[i];
            if(num > arr[i - 1] + 1){
                num = arr[i - 1] + 1;
                arr[i] = num;
            }
            ans = max(ans, num);
        }

        return ans;
    }
};