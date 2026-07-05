/*
 * Problem: 1301. Number of Paths with Max Score
 * Link: https://leetcode.com/problems/number-of-paths-with-max-score
 * Author: LatifY
 * Date: 05 July 2026
 * Time Complexity: O(N^2)
 * Space Complexity: O(N^2)
 */

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        long long mod = 1e9 + 7;

        vector<vector<int>> dpScore(n, vector<int>(n, -1));
        vector<vector<int>> dpPaths(n, vector<int>(n, 0));

        dpScore[n - 1][n - 1] = 0;
        dpPaths[n - 1][n - 1] = 1;

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {1, 1}};

        for(int r = n - 1; r >= 0; r--){
            for(int c = n - 1; c >= 0; c--){
                if((r == n - 1 && c == n - 1) ||board[r][c] == 'X') continue; //init state

                for(int i = 0; i < 3; i++){
                    int pr = r + dirs[i].first;
                    int pc = c + dirs[i].second;

                    if(pr < n && pc < n && dpPaths[pr][pc] > 0){
                        int val = board[r][c] == 'E' ? 0 : board[r][c] - '0';
                        int newScore = dpScore[pr][pc] + val;

                        if(newScore > dpScore[r][c]){
                            dpScore[r][c] = newScore;
                            dpPaths[r][c] = dpPaths[pr][pc];
                        }
                        else if(newScore == dpScore[r][c]){
                            dpPaths[r][c] = (dpPaths[r][c] +  dpPaths[pr][pc]) % mod;
                        }
                    }
                }
            }
        }

        if(dpPaths[0][0] == 0) return {0, 0};
        return {dpScore[0][0], dpPaths[0][0]};

    }
};