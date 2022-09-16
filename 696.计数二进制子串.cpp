/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ptr=0, last=0, ans=0;
        while(ptr < s.size()){
            char c = s[ptr];
            int count = 0;
            while(ptr < s.size() && s[ptr] == c){
                ++count;
                ++ptr;
            }
            ans += min(count, last);
            last = count;
        }
        return ans;
    }
};
// @lc code=end

