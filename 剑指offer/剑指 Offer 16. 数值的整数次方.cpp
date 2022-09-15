class Solution {
public:
	// 快速幂正负数完整版
    double myPow(double x, int n) {
        double ans = 1.0;
        while(n){
            if (n & 1){
                if (n > 0) ans *= x;
                else ans /= x;
            }
            n *= 0.5;
            x *= x;
        }
        return ans;
    }
};