// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem76.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()==0 || t.size()==0 || s.size()<t.size()) return "";

        int win[128] = {0};
        int need[128] = {0};
        for(int i=0; i<t.size(); ++i){
            ++need[t[i]];
        }
        // 定义窗口指针 最短长度 已经匹配计数 开始位置
        int left=0, right=0, minLen=s.size()+1, count=0, start=0;
        while(right < s.size()){
            if(win[s[right]] < need[s[right]]){
                ++count;
            }
            ++win[s[right]];
            ++right;

            while(count == t.size()){
                if(right-left < minLen){
                    minLen = right - left;
                    start = left;
                }
                if(win[s[left]] == need[s[left]])
                    --count;
                --win[s[left]];
                ++left;
            }
        }

        if(minLen == s.size()+1)
            return "";
        return s.substr(start, minLen);
    }
};
// @lc code=end

