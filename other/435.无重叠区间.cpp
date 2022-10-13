/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        int n = intervals.size();
        int keep = 1, currend = intervals[0][1];
        for(int i=1; i<n; ++i){
            if(intervals[i][0] >= currend){
                ++keep;
                currend = intervals[i][1];
            }
        }
        return n - keep;
    }
};
// @lc code=end

