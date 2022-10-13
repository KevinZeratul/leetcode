// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem43.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    // 本题有傅里叶变换O(clogc)解法
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.size(), n = num2.size();
        vector<int> ansArr(m + n);
        // 1.num1与num2乘积长度为m+n-1或m+n;
        // 2.num1[i] * num2[j]的结果位于ansArr[i+j+1]需要判断进位
        // 3.需要舍弃为0的最高位
        for (int i = m-1; i >= 0; --i){
            int x = num1.at(i) - '0';
            for (int j = n-1; j >= 0; --j){
                int y = num2.at(j) - '0';
                ansArr[i + j + 1] += x * y; 
            }
        }
        for (int i = m+n-1; i > 0; --i){
            ansArr[i-1] += ansArr[i] / 10;
            ansArr[i] %= 10;
        }
        int idx = ansArr[0] == 0 ?  1 : 0;
        string ans;
        while (idx < m + n){
            ans.push_back(ansArr[idx] + '0');
            ++idx;
        }
        return ans;
    }
};
// @lc code=end

