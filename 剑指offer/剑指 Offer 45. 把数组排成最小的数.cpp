class Solution {
public:
    string minNumber(vector<int>& nums) {
        // 自定义排序 x+y > y+x 则 x > y
        vector<string> strs;
        for (int i=0; i<nums.size(); ++i)
            strs.emplace_back(to_string(nums[i]));
        sort(strs.begin(), strs.end(), [](string& x, string& y){ return x+y < y+x;});
        string res;
        for(string s : strs)
            res += s;
        return res;
        // quickSort(strs, 0, strs.size()-1);
        
    }
    // 修改后的快排
    // void quickSort(vector<string>& strs, int l, int r){
    //     if (l >= r) return;
    //     int i = l, j = r;
    //     while (i < j){
    //         while (strs[j] + strs[l] >= strs[l] + strs[j]) --j;
    //         while (strs[i] + strs[l] <= strs[l] + strs[i]) ++i;
    //         swap(strs[i], strs[j]);
    //     }
    //     swap(strs[i], strs[l]);
    //     quickSort(strs, l, i-1);
    //     quickSort(strs, i+1, r);
    // }
};