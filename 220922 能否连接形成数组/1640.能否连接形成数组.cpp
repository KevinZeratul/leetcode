/*
 * @lc app=leetcode.cn id=1640 lang=cpp
 *
 * [1640] 能否连接形成数组
 */

// @lc code=start
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        // O(n) O(n)
        unordered_map<int, int> idx;
        for (int i=0; i<pieces.size(); ++i)
            idx[pieces[i][0]] = i;
        for (int i=0; i<arr.size(); ){
            auto it = idx.find(arr[i]);
            if (it == idx.end()) return false;
            for (int val : pieces[it->second]){
                if (val != arr[i++]) return false;
            }
        }
        return true;
    }
};
// @lc code=end

