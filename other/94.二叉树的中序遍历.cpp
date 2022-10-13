/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
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
    vector<int> inorderTraversal(TreeNode* root) {
        /* Morris 中序遍历 O(n) O(1)*/
        vector<int> nums;
        TreeNode* pre = nullptr;
        
        while(root!=nullptr){
            if(root->left != nullptr){
                pre = root->left;
                while(pre->right != nullptr && pre->right != root)
                    pre = pre->right;
                if(pre->right == nullptr){
                    pre->right = root;
                    root = root->left;
                }
                else{
                    nums.emplace_back(root->val);
                    root = root->right;
                    pre->right = nullptr;
                }    
            }
            else{
                nums.emplace_back(root->val);
                root = root->right;
            }
        }
        return nums;    
    }
};
// @lc code=end

