class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        unordered_set<int> s;
        stack<int> st;
        int idx = 0;
        for(int cur : popped){
            if (s.find(cur) != s.end()){
                if(st.top() == cur){
                    st.pop();
                    s.erase(cur);
                    continue;
                }
                else return false;
            } 
            while(pushed[idx] != cur){
                s.insert(pushed[idx]);
                st.push(pushed[idx]);
                ++idx;
            }
            if (s.count(cur))
                s.erase(cur);
            ++idx;
        }
        return true;
    }
};