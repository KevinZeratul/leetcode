class Solution {
public:
    // O(n) O(1)
    // 常见方法 1.加和 2.异或 3.原地hash 
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size() + 2;
        int sumall = 0;
        for (int i=1; i<=n; ++i) sumall ^= i;
        for (int num : nums) sumall ^= num;
        int lowestone = sumall & (-sumall);
        int num1 = 0, num2 = 0;
        for (int num : nums){
            if (lowestone & num)
                num1 ^= num;
            else
                num2 ^= num;
        }
        for (int i=1; i<=n; ++i){
            if (lowestone & i)
                num1 ^= i;
            else
                num2 ^= i;
        }
        return {num1, num2};
    }
};