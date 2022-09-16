/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0; i<s.size(); ++i){
            count += countHuiwen(s, i, i);
            count += countHuiwen(s, i, i+1);
        }
        return count;
    }
    
    int countHuiwen(const string &s, int l, int r){
        int count = 0;
        while(l>=0 && r<s.size() && s[l] == s[r]){
            ++count;
            --l; 
            ++r;
        }
        return count;
    }
};
// @lc code=end

