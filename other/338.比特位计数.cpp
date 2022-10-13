/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> cnt(n+1, 0);
        for(int i=0; i<=n; ++i){
            cnt[i] = (i&1) ? cnt[i-1]+1 : cnt[i>>1];
        }
        return cnt;
    }
};
// @lc code=end

