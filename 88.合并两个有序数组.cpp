/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size()-1;
        --m; --n;
        while (n >= 0){
            while (m >= 0 && nums1[m] > nums2[n]){
                swap(nums1[m--], nums1[i--]);
            }
            swap(nums2[n--], nums1[i--]);
        }
    }
};
// @lc code=end

