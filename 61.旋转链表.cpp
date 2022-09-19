/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==nullptr || head->next==nullptr) return head;
        int len = 1;
        ListNode* cur = head;
        while(cur->next != nullptr){
            ++len;
            cur = cur->next;
        }
        int move = len - (k%len);
        if(move == len) return head;
        cur->next = head;
        while(move--){
            cur = cur->next;
        }
        ListNode* newhead = cur->next;
        cur->next = nullptr;
        return newhead;
    }
};
// @lc code=end

