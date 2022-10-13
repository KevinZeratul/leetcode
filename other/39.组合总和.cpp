/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0, 0);
        return ans;
    }
    vector<vector<int>> ans;
    vector<int> res;
    void dfs(vector<int>& candidates, int target, int curidx, int cursum){
        if (cursum == target){
            ans.push_back(res);
            return;
        }
        if (cursum > target) return;
        for (int i=curidx; i<candidates.size(); ++i){
            res.push_back(candidates[i]);
            cursum += candidates[i];
            dfs(candidates, target, i, cursum);
            cursum -= candidates[i];
            res.pop_back();
        }
    }
};
// @lc code=end

