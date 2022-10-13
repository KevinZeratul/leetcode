/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, idx = 0;
        for (int i = 0; i < arr.size(); ++i){
            idx = max(idx, arr[i]);
            if (idx == i) ++ans;
        }
        return ans;
    }
};
// @lc code=end

