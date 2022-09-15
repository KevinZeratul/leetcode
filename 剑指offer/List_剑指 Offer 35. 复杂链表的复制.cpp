/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        
        Node* cur = head;
        for (; cur != NULL; cur = cur->next->next){
            Node* node = new Node(cur->val);
            node->next = cur->next;
            cur->next = node;
        }
        for (cur = head; cur != NULL; cur = cur->next->next){
            if (cur->random != NULL)
                cur->next->random = cur->random->next;
            else
                cur->next->random = NULL;
        }
        Node* newhead = head->next;
        for (cur = head; cur != NULL; cur = cur->next){
            Node* node = cur->next;
            cur->next = cur->next->next;
            if (node->next)
                node->next = node->next->next;
            else
                node->next = NULL;
        }
        return newhead;
    }
};