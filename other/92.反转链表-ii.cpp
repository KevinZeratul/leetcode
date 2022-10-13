// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem92.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        bool flag = 0; //head是否发生改变
        if(left == 1) flag = 1; 
        ListNode* curr = new ListNode(0);
        curr->next = head;
        for(int i=1; i<left; ++i){
            curr = curr->next;
        }
        ListNode* home = curr;
        curr = curr->next;
        ListNode* prev = nullptr;
        ListNode* revhead = nullptr;
        while(curr!=nullptr && left<=right){
            if(left == right) revhead = curr;
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            ++left;
        }
        home->next->next = curr;
        home->next = revhead;
        if(flag) head = revhead;
        return head;
    }
};
// @lc code=end

