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
    void inOrderDFS(TreeNode* root, int k, int* ans, int* depth){
        auto left = root->left;
        auto right = root->right;
        if(left != nullptr)inOrderDFS(left, k, ans, depth);
        *depth += 1;
        if(*depth == k){
            *ans = root->val;
        }
        if(right != nullptr)inOrderDFS(right, k, ans, depth);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int depth = 0;
        inOrderDFS(root, k, &ans, &depth);
        return ans;
    }
};
