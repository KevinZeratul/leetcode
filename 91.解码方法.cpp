/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int f1 = 1, f2 = 0, fi;
        for (int i=1; i<=n; ++i){
            fi = 0;
            if (s[i-1] != '0')
                fi += f1;
            if (i > 1 && s[i-2] != '0' && 10 * (s[i-2]-'0') + (s[i-1]-'0') <= 26)
                fi += f2;
            f2 = f1;
            f1 = fi;
        }
        return fi;
    }
};
// @lc code=end

