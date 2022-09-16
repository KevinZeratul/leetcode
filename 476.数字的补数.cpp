/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        int highidx = 0;
        for(int i=1; i<=30; ++i){
            if(num >= (1<<i))
                highidx = i;
        }
        int mask = (highidx==30) ? 0x7fffffff : (1<<(highidx+1))-1;
        return num ^ mask;
    }
};
// @lc code=end

