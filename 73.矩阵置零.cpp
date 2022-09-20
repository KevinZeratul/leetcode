/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 从两个数组标记O(m+n) 到两个标记变量O(1) 到一个标记变量O(1)
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false;
        
        for (int i=0; i<m; ++i){
            if (!matrix[i][0]) flag_col0 = true;
            for (int j=1; j<n; ++j){
                if (!matrix[i][j])
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for (int i=m-1; i>= 0; --i){
            for (int j=1; j<n; ++j){
                if (!matrix[i][0] || !matrix[0][j])
                    matrix[i][j] = 0;
            }
            if (flag_col0)
                matrix[i][0] = 0;
        }
    }
};
// @lc code=end
