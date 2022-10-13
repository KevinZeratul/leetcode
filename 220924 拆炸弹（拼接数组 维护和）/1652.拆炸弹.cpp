/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 *
 * [1652] 拆炸弹
 */

// @lc code=start
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);
        code.resize(n * 2);
        copy(code.begin(), code.begin()+n, code.begin()+n);
        if (k == 0) return ans;
        int l = k>0 ?  1 : n+k;
        int r = k>0 ?  k : n-1;
        int tempsum = 0;
        for (int i=l; i<=r; ++i)
            tempsum += code[i];
        for (int i=0; i<n; ++i){
            ans[i] += tempsum;
            tempsum -= code[l];
            tempsum += code[r+1];
            ++l;
            ++r;
        }
        return ans;      
    }
};
// @lc code=end

