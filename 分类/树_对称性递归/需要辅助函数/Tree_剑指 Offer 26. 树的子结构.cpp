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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL || B == NULL) return false;
        if (A->val == B->val){
            // 匹配到头结点了
            if (detect(A, B)) return true;
        }
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool detect(TreeNode* A, TreeNode* B){
        if (B == NULL) return true;
        if (A == NULL || A->val != B->val) return false;
        return detect(A->left, B->left ) && detect(A->right, B->right);
    }
};