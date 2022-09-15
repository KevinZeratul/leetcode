/*
 * @lc app=leetcode.cn id=672 lang=cpp
 *
 * [672] 灯泡开关 Ⅱ
 */

// @lc code=start
class Solution {
public:
    int flipLights(int n, int presses) {
        // 脑筋急转弯，更多分类情况
        if (presses == 0) return 1;
        if (n == 1) return 2;
        else if (n == 2) return presses==1 ?  3 : 4;
        else return presses==1 ?  4 : presses==2 ?  7 : 8;
    }
};
// @lc code=end

