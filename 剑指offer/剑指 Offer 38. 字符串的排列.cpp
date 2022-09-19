class Solution {
public:
    vector<string> permutation(string s) {
        dfs(s, 0);
        return res;
    }

    vector<string> res;
    // x代表x之前的位已经固定，从x为开始交换
    void dfs(string s, int x){
        if (x == s.size()-1){
            res.emplace_back(s);
            return;
        } 
        set<int> same;
        for (int i=x; i<s.size(); ++i){
            if (same.find(s[i]) != same.end()) continue; // 遇到相同字符，剪枝
            same.insert(s[i]);
            swap(s[i], s[x]);
            dfs(s, x+1);
            swap(s[i], s[x]);
        }
    }
};