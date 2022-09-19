/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    static bool cmp(ListNode* l1, ListNode* l2){
        return l1->val < l2->val;
    }

    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        vector<ListNode*> nodes;
        ListNode* cur = head;
        while(cur != nullptr){
            nodes.emplace_back(cur);
            cur = cur->next;
        }
        sort(nodes.begin(), nodes.end(), cmp);
        int i;
        for(i=0; i<nodes.size()-1; ++i){
            nodes[i]->next = nodes[i+1];
        }
        nodes[i+1]->next = nullptr;
        return head;
    }
};
// @lc code=end

