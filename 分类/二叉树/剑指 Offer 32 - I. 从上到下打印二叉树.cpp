/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        deque<TreeNode *> dque;
        vector<int> res;
        if (!root) return res;
        dque.push_back(root);
        while (!dque.empty()){
            TreeNode* node = dque.front();
            res.push_back(node->val);
            
            if (node->left) dque.push_back(node->left);
            if (node->right) dque.push_back(node->right);
            dque.pop_front();
        }
        return res;
    }
};