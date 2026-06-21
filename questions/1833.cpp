/*
 * Problem: 1833. Maximum Ice Cream Bars
 * Link: https://leetcode.com/problems/maximum-ice-cream-bars
 * Author: LatifY
 * Date: 21 June 2026
 * Time Complexity: O(n + k)
 * Space Complexity: O(n + k)
 */

class Solution {
public:
    void countingSort(vector<int>& arr, int n){
        int maxElem = *max_element(arr.begin(), arr.end());
        vector<int> tr(maxElem + 1, 0);

        for(int i = 0; i < n; i++){
            tr[arr[i]]++;
        }

        for(int i = 1; i < maxElem + 1; i++){
            tr[i] += tr[i - 1];
        }

        for(int i = maxElem; i > 0; i--){
            tr[i] = tr[i - 1];
        }
        tr[0] = 0;

        vector<int> res(n, 0);
        for(int i = 0; i < n; i++){
            int trIdx = tr[arr[i]]++;
            res[trIdx] = arr[i];
        }
        arr = res;
    }

    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        countingSort(costs, n);

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(costs[i] <= coins){
                coins -= costs[i];
                ans++;
            }
        }

        return ans;
    }
};