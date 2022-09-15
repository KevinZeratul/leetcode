class Solution {
public:
    long mypow(long n, long m){
        if (m == 0) return 1;
        long k = mypow(n, m>>1) % 1000000007;
        if (m & 1) return (n*k*k) % 1000000007;
        else return (k*k) % 1000000007;
    }

    int cuttingRope(int n) {
        if (n < 4) return n-1;
        // 递归快速幂
        long k = n % 3; 
        n /= 3;
        if (k == 0) return (int)mypow(3, n);
        else if (k == 1) return (int)(mypow(3, n-1) *4 % 1000000007);
        else return (int)(mypow(3, n) * 2 % 1000000007);
    }
};