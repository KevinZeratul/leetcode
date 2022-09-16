// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem318.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> hash;
        int ans = 0;
        for(const string &word : words){
            int mask = 0;
            int wordLen = word.size();
            for(const auto &ch : word){
                mask |= 1 << (ch-'a');
            }
            hash[mask] = max(hash[mask], wordLen);
            for(const auto& [h_mask, h_Len] : hash){
                if(!(mask & h_mask))
                    ans = max(ans, wordLen*h_Len);
            }
        }
        return ans;
    }
};
// @lc code=end

