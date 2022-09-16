/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        /* 法一 vector存指针*/
        // if(head==nullptr || head->next==nullptr || head->next->next==nullptr) return;
        // vector<ListNode*> pointer;
        // ListNode* cur = head;
        // while(cur != nullptr){
        //     pointer.emplace_back(cur);
        //     cur = cur->next;
        // }
        // cur = head;
        // //也可以对pointer中的指针直接操作
        // for(int i=1, j=pointer.size()-1; i<j; ++i, --j){
        //     cur->next = pointer[j];
        //     cur->next->next = pointer[i];
        //     cur = cur->next->next;
        //     if(i+2 == j){
        //         cur->next = pointer[j-1];
        //         cur = cur->next;
        //         break;
        //     }
        // }
        // cur->next = nullptr;
        // return;

        /* 法二 找中点+后半段翻转+合并连接 */
        if(head == nullptr) return;
        ListNode* mid = findMiddle(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
        return;
    }
    //这里找到的是中点的前一个节点，方便翻转
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* prev= nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void mergeList(ListNode* l1, ListNode* l2){
        ListNode *l1next, *l2next;
        while(l1!=nullptr && l2!=nullptr ){
            l1next = l1->next;
            l2next = l2->next;
            
            l1->next = l2;
            l1 = l1next;
            l2->next = l1;
            l2 = l2next;
        }
    }
};
// @lc code=end

