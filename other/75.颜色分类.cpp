/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    // 单指针 两次遍历 O(n) O(1)
    // void sortColors(vector<int>& nums) {
    //     int n = nums.size();
    //     int ptr = 0;
    //     for (int i = 0; i < n; ++i) {
    //         if (nums[i] == 0) {
    //             swap(nums[i], nums[ptr]);
    //             ++ptr;
    //         }
    //     }
    //     for (int i = ptr; i < n; ++i) {
    //         if (nums[i] == 1) {
    //             swap(nums[i], nums[ptr]);
    //             ++ptr;
    //         }
    //     }
    // }
  
    // 双指针 一次遍历 O(n) O(1)
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p1 = 0;
        for (int i=0; i<n; ++i){
            if (nums[i] == 1){
                swap(nums[p1], nums[i]);
                ++p1;
            }
            if (nums[i] == 0){
                swap(nums[p0], nums[i]);
                if (p0 < p1){
                    swap(nums[p1], nums[i]);
                }
                ++p1;
                ++p0;
            }
        } 
    }
};
// @lc code=end

