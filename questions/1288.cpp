/*
 * Problem: 1288. Remove Covered Intervals
 * Link: https://leetcode.com/problems/remove-covered-intervals
 * Author: LatifY
 * Date: 06 July 2026
 * Time Complexity: O(N log N)
 * Space Complexity: O(log N)
 */

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int ans = 0;
        int maxR = 0;

        for(const auto& interval : intervals){
            if(interval[1] > maxR){
                ans++;
                maxR = interval[1];
            }
        }

        return ans;
    }
};