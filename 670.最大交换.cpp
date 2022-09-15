/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */

// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        string numstr = to_string(num);
        int n = numstr.size();
        int maxIdx = n-1;
        int idx1 = -1, idx2 = -1;
        for( int i = n-1; i>=0; --i){
            if( numstr[i] > numstr[maxIdx]){
                maxIdx = i;
            }
            else if( numstr[i] < numstr[maxIdx]){
                idx1 = i;
                idx2 = maxIdx;
            }    
        }
        if( idx1 >= 0){
            swap(numstr[idx1], numstr[idx2]);
            int num = stoi(numstr);
            return num;
        }
        else return num;
    }
};
// @lc code=end

