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
    TreeNode* find_and_build(const vector<int>& preorder, const vector<int>& inorder,
    int preorder_left, int preorder_right, int inorder_left, int inorder_right){
        if(preorder_left > preorder_right) return nullptr;
        
        // 确定前序和中序根节点的索引
        int preorder_root = preorder_left;
        int inorder_root = index[preorder[preorder_root]];

        TreeNode* root = new TreeNode(preorder[preorder_root]);
        // 取左子树节点数目
        int size_left = inorder_root - inorder_left;
        root->left = find_and_build(preorder, inorder, preorder_left+1, preorder_root+size_left, inorder_left, inorder_root-1);
        root->right = find_and_build(preorder, inorder, preorder_left+size_left + 1, preorder_right, inorder_root+1, inorder_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0; i<n; ++i){
            index[inorder[i]] = i;
        }
        return find_and_build(preorder, inorder, 0, n-1, 0, n-1);
    }

private:
    // 哈希映射表，用于在O(1)复杂度查找中序遍历的根节点
    unordered_map<int, int> index;
};