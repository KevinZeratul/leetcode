/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gidx=0, sidx=0;
        while(gidx < g.size() && sidx < s.size()){
            if(g[gidx] <= s[sidx]) gidx++;
            sidx++;
        }
        return gidx;
    }
};
// @lc code=end

