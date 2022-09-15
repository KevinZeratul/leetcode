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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        deque<TreeNode *> dque;
        dque.push_back(root);
        while (!dque.empty()){
            int size = dque.size();
            res.emplace_back(vector<int> ());
            for (int i=0; i<size; ++i){
                TreeNode *node = dque.front();
                dque.pop_front();
                res.back().emplace_back(node->val);
                if (node->left) dque.push_back(node->left);
                if (node->right) dque.push_back(node->right);
            }
        }
        return res;
    }
};