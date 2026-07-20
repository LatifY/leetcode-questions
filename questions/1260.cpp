/*
 * Problem: 1260. Shift 2D Grid
 * Link: https://leetcode.com/problems/shift-2d-grid
 * Author: LatifY
 * Date: 20 July 2026
 * Time Complexity: O(M * N)
 * Space Complexity: O(M * N)
 */

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int total = m * n;
        k %= total;

        vector<int> arr(total);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                arr[i * n + j] = grid[i][j];
            }
        }

        vector<int> shiftedArr(total);
        for(int i = 0; i < total; i++){
            int pos = (i + k) % total;
            shiftedArr[pos] = arr[i];
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                grid[i][j] = shiftedArr[i * n + j];
            }
        }

        return grid;
    }
};