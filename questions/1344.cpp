/*
 * Problem: 1344. Angle Between Hands of a Clock
 * Link: https://leetcode.com/problems/angle-between-hands-of-a-clock
 * Author: LatifY
 * Date: 18 June 2026
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12) hour = 0;
        double hourAngle = ((double)hour + ((double)minutes / 60)) * 30;
        double minutesAngle = minutes * 6;

        double res = abs(hourAngle - minutesAngle);

        return res <= 180 ? res : 360 - res;
    }
};
