/*
 * Problem: 1291. Sequential Digits
 * Link: https://leetcode.com/problems/sequential-digits
 * Author: LatifY
 * Date: 13 July 2026
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

class Solution {
public:
//1 2 3 4 5 6 7 8 9 (9)
//12 23 34 45 .. 89 (8)
//123 234 345 ... 789 (7)
// 1234 2345 ... 6789 (6)
//123456789 (1) 9 * 10 / 2 = 45
    vector<int> sequentialDigits(int low, int high) {
        vector<long long> preComputedSequentialDigits;

        for(int i = 1; i <= 9; i++){
            for(int j = 0; j <= 9 - i; j++){
                int count = i - 1;
                long long num = j + 1;
                int currentDigit = j + 1;

                while(count > 0){
                    currentDigit++;
                    num = num * 10 + currentDigit;
                    count--;
                }

                if (num >= low && num <= high) {
                    preComputedSequentialDigits.push_back(num);
                }
            }

            
        }

        vector<int> ans;
        for(int i = 0; i < preComputedSequentialDigits.size(); i++){
            ans.push_back(preComputedSequentialDigits[i]);
        }

        return ans;


    }
};