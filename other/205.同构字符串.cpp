/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> sf(256, 0), tf(256, 0);
        for(int i=0; i<s.size(); ++i){
            if(sf[s[i]] != tf[t[i]]) return false;
            sf[s[i]] = tf[t[i]] = i+1;
        }
        return true;
    }
};
// @lc code=end

