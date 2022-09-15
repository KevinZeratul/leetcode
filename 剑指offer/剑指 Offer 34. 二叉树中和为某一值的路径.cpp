/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        search(root, 0, target);
        return ans;
    }

    void search(TreeNode* root, int cursum, int target){
        if (!root) return;
        path.emplace_back(root->val);
        cursum += root->val;
        if(cursum == target && root->left == NULL && root->right == NULL)
            ans.push_back(path);
        search(root->left, cursum, target);
        search(root->right, cursum, target);
        cursum -= root->val;
        path.pop_back();
    }
};