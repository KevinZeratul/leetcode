/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        ListNode* cur = head;
        while(cur != nullptr){
            if(visited.count(cur)){
                return true;
            }
            visited.insert(cur);
            cur = cur->next;
        }
        return false;
    }
    // 本题也可以用快慢指针（Floyd判圈）完成
};
// @lc code=end

