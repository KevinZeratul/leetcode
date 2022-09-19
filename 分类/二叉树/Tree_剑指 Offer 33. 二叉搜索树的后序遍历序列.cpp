class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        // 1.递归 O(n^2) O(n)
        // return recur(postorder, 0, postorder.size()-1);
        // 2.单调栈 O(n) O(n)
        stack<int> st;
        int root = INT_MAX;
        for (int i=postorder.size()-1; i>=0; --i){
            if (root < postorder[i]) return false;
            while (!st.empty() && postorder[i] < st.top()){
                root = st.top();
                st.pop();
            }
            st.push(postorder[i]);
        }
        return true;
    }
    // bool recur(vector<int>& postorder, int i, int j){
    //     if (i >= j) return true;
    //     int cur = i;
    //     while (postorder[cur] < postorder[j]) ++cur;
    //     int rstart = cur;
    //     while (postorder[cur] > postorder[j]) ++cur;
    //     return cur == j && recur(postorder, i, rstart-1) && recur(postorder, rstart, j-1);
    // }
};