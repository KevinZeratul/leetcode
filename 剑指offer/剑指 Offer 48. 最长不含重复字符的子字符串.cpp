class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> same;
        int back = -1, ans = 0;
        for (int i=0; i<s.size(); ++i){
            if (i) same.erase(s[i-1]);
            while (back+1 < s.size() && !same.count(s[back+1])){
                same.insert(s[back+1]);
                ++back;
            }
            ans = max(ans, back-i+1);
        }
        return ans;
    }

};