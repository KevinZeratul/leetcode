// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem24.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        // 递归 O(n) O(n)
        // if(head == nullptr || head->next == nullptr) return head;
        // ListNode* newhead = head->next;
        // head->next = swapPairs(newhead->next);
        // newhead->next = head;
        // return newhead;

        // 迭代 O(n) O(1)
        ListNode* addhead = new ListNode();
        addhead->next = head;
        ListNode* temp = addhead;
        while(temp->next != nullptr && temp->next->next != nullptr){
            ListNode* node1 = temp->next;
            ListNode* node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return addhead->next;

    }
};
// @lc code=end

