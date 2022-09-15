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
        dque.emplace_back(root);
        bool isOrderLeft = true;
        while (!dque.empty()){
            int size = dque.size();
            deque<int> temp;
            for (int i=0; i<size; ++i){
                TreeNode *node = dque.front();
                dque.pop_front();
                if (isOrderLeft)
                    temp.emplace_back(node->val);
                else 
                    temp.emplace_front(node->val);
                if (node->left) dque.emplace_back(node->left);
                if (node->right) dque.emplace_back(node->right);
            }
            res.emplace_back(vector<int>{temp.begin(), temp.end()});
            isOrderLeft = !isOrderLeft;
        }
        return res;
    }
};