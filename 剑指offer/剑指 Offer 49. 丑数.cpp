class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        int ia = 1, ib = 1, ic = 1;
        for (int i=2; i<n+1; ++i){
            int numa = dp[ia] * 2, numb = dp[ib] * 3, numc = dp[ic] * 5;
            dp[i] = min(min(numa, numb), numc);
            if (dp[i] == numa) ++ia;
            if (dp[i] == numb) ++ib;
            if (dp[i] == numc) ++ic;
        }
        return dp[n];
    }
};