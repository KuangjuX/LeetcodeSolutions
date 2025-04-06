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
    void swap(TreeNode* node){
        auto left = node->left;
        node->left = node->right;
        node->right = left;
    }

    void invert(TreeNode* root){
        swap(root);
        if(root->left != nullptr)invert(root->left);
        if(root->right != nullptr)invert(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)return root;
        invert(root);
        return root;
    }
};
