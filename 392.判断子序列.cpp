/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto it1 = s.begin();
        auto it2 = t.begin();
        while(it1!=s.end() && it2!=t.end()){
            if(*it1 == *it2) ++it1;
            ++it2;
        }
        if(it1 == s.end()) return true;
        else return false;
    }
};
// @lc code=end

