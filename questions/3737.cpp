/*
 * Problem: 3737. Count Subarrays With Majority Element I
 * Link: https://leetcode.com/problems/count-subarrays-with-majority-element-i
 * Author: LatifY
 * Date: 25 June 2026
 * Time Complexity: O(N log N)
 * Space Complexity: O(N log N)
 */

class Solution {
public:
    vector<long long> getPrefixSum(vector<int>& nums, int n, int target){
        vector<long long> pre(n + 1, 0);

        for(int i = 0; i < n; i++){
            int val = (nums[i] == target) ? 1 : -1;
            pre[i + 1] = pre[i] + val;
        }
        return pre;
    }
    
    //fenwick tree
    vector<int> bit;
    int bitSize;

    void update(int idx, int val){
        while(idx <= bitSize){
            bit[idx] += val;
            idx += (idx & -idx);
        }
    }

    int query(int idx){
        int sum = 0;
        while(idx > 0){
            sum += bit[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    void printArr(vector<long long>& arr){
        for(int i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> pre = getPrefixSum(nums, n, target);
        bitSize = 2 * n + 3;
        bit.resize(bitSize + 1, 0);
        int offset = n + 2; // for negative values

        long long ans = 0;
        for(int i = 0; i < n + 1; i++){
            int shiftedIdx = pre[i] + offset;
            ans += query(shiftedIdx - 1);
            update(shiftedIdx, 1);
        }

        return ans;
    }
};

