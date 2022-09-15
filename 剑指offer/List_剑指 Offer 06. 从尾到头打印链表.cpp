class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        ListNode *p = head;
        vector<int> ret;
        stack<int> st;
        while(p){
            st.push(p->val);
            p = p->next;
        }
        while(!st.empty()){
            ret.push_back(st.top());
            st.pop();
        }
        return ret;
    }
};