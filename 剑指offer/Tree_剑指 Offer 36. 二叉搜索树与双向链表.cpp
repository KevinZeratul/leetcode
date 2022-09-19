/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;                   
        right = _right;
    }
};
*/
class Solution {
public:
    Node *pre, *head = NULL;
    void recur(Node* cur){
        if (!cur) return;
        recur(cur->left);
        if (pre) pre->right = cur;
        else head = cur;
        cur->left = pre;
        pre = cur;
        recur(cur->right);
    }

    Node* treeToDoublyList(Node* root) {
        if (!root) return NULL;
        recur(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
};